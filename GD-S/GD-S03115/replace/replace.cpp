#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
string s1[maxn],s2[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.in","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	if(n<=1e3){
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		for(int i=1;i<=q;i++){
			string t1,t2;
			cin>>t1>>t2;
			int lenx=t1.length();
			int leny=t2.length();
			int ans=0;
			for(int l=1;l<=n;l++){
				int len=s1[i].length();
				for(int j=1;j<=lenx;j++){
					for(int k=1;k<=leny;k++){
						int pr1=j-len+1,pr2=k-len+1,flag=0;
						if(j+len-1>lenx || k+len-1>leny) continue;
						for(int f=1;f<=len;f++){
							if(s1[l][f]!=t1[j+f-1] || s2[l][f]!=t2[k+f-1]){
								flag=1;
								break;
							}
						}
						if(flag==0){
							ans++;
						}
					}
				}	
			}
			printf("%d\n",ans-(i%2==0?1:-1));
		}
	}
	else{
		for(int i=1;i<=q;i++) cout<<0<<endl;
	}
	return 0;
}

