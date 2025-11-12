//3-replace
#include<bits/stdc++.h>
using namespace std;
string str[200005][2];
int a[200005];
long long ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	//cin>>n>>q;
//	cout<<n<<q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
		a[i]=str[i][0].size(); 
	}
	string s,t;
	while(q--){
		ans=0;
		cin>>s>>t;
		if(s.size()!=t.size()){
			printf("0\n");
			//cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int p=s.find(str[i][0]);
			while(p!=-1){
				string r=s;
				r.replace(p,a[i],str[i][1]);
				ans+=(r==t);
				p=s.find(str[i][0],p+1);
				//cout<<i<<" "<<p<<endl;
			}
		}
		printf("%lld\n",ans);
	//	cout<<ans<<"\n";
	}
	return 0;
}
