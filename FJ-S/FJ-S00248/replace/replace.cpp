#include<bits/stdc++.h>
using namespace std;
#define ll long long
//rerecycyclcl
int n,q,pie[5000100],ans;
string s[200100][2],a1,a2;
bool cook(string s,string t,string peek,string ddkk){
	string nj=t+'#'+s;
	int n=nj.size();
	int m=t.size();
	//cout<<nj<<' '<<n<<' '<<m<<endl; 
	for(int i=0;i<n;i++)pie[i]=0;
	//cout<<0<<' ';
	for(int i=1;i<n;i++){
		int j=i;
		while(j>0){
			if(nj[i]==nj[pie[j-1]]){
				pie[i]=pie[j-1]+1;
				break;
			}
			j=pie[j-1];
		}
		//cout<<pie[i]<<' ';
	}
	//cout<<endl;
	for(int i=1;i<n;i++){
		if(pie[i]==m){
			//cout<<i<<' ';
			string gan=s;
			for(int j=i-m-m;j<=i-m-1;j++){
				gan[j]=ddkk[j-i+m+m];
			}
			//cout<<gan<<' ';
			if(gan==peek){
				//cout<<endl;
				return 1;
			}
		}
	}
	//cout<<endl;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>a1>>a2;
		ans=0;
		for(int i=1;i<=n;i++){
			if(cook(a1,s[i][0],a2,s[i][1])){
				ans++;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
