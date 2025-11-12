#include<bits/stdc++.h>
using namespace std;
const int NQmax=200000;
int rep[NQmax+5][2][2];
//rep[ReplacingNo.][From/To][Left/Right]
struct int2{
	int a,b;
};
int2 chstring(string a){
	int2 rtn;
	for(int j=0;j<a.size();j++){
		if(a[j]=='b'){
			rtn.a=j;
			rtn.b=a.size()-j;
		}
	}return rtn;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;
	// Special B 6/9/10/15/16 [25] Enchant4
	cin>>n>>Q;
	string rpa,rpb,a,b;
	for(int i=0;i<n;i++){
		cin>>rpa>>rpb;
		int2 rpaa=chstring(rpa),rpba=chstring(rpb);
		rep[i][0][0]=rpaa.a;
		rep[i][0][1]=rpaa.b;
		rep[i][1][0]=rpba.a;
		rep[i][1][1]=rpba.b;
	}
	while(Q--){
		int ans=0;
		cin>>a>>b;
		int2 a2=chstring(a),b2=chstring(b);
		for(int i=0;i<n;i++){
			if(a2.a>=rep[i][0][0]&&a2.b>=rep[i][0][1]&&
			   a2.a-rep[i][0][0]+rep[i][1][0]==b2.a&&
			   a2.b-rep[i][0][1]+rep[i][1][1]==b2.b)ans++;
		}cout<<ans<<endl;
	}
}
