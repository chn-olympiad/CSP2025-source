#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	map<string,string> f;
	f[""] = "&&&&&";
	for(int i=1;i<=n;i++){
		string frm,tu;
		cin >> frm >> tu;
		f[frm] = tu;
	}
	
	auto chuai = [&](string frm,string tu){
		long long cnt = 0;
		int i=0,j=frm.length()-1;
		for(;i<frm.length();i++){
			if(frm[i]!=tu[i])break;
		}	
		for(;j>=0;j--){
			if(frm[j]!=tu[j])break;
		}
		
		
		string tsfr,tstu;
		for(int k=i;k<=j;k++){
			tsfr += frm[k];
			tstu += tu[k];
		}
		
//		cout << "#" << tsfr << ' ' << tstu << '\n';
		
		for(int prelen=0;i-prelen>=0;prelen++){
			if(prelen){
				tsfr = frm[i-prelen] + tsfr;
				tstu = tu[i-prelen] + tstu;
			} 
			string Tf = tsfr,Tu = tstu;
			for(int nxtlen=0;j+nxtlen<frm.length();nxtlen++){
				if(nxtlen){
					Tf[Tf.length()] = frm[j+nxtlen];
					Tu[Tu.length()] = tu[j+nxtlen];
				}
//				cout << "## " << Tf << ' ' << Tu << '\n';
				if(f[Tf] == Tu){
					cnt++;
				}
			}
		}
		return cnt;
	};
	
	while(q--){
		string frm,tu;
		cin >> frm >> tu;
		if(frm.length() != tu.length()){
			cout << "0\n";
			continue;
		}
		cout << chuai(frm,tu) << '\n';
	}
	cout << flush;
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
