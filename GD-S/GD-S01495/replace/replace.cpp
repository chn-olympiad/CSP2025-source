#include<bits/stdc++.h>
using namespace std;
struct strinn{
	string s1,s2;
	int l;
}node[200010];
bool cmp(strinn x,strinn y){
	return x.l<y.l;
}
int n,p;
string ss1,ss2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		cin>>node[i].s1>>node[i].s2;
		node[i].l=node[i].s1.size();
	}
	sort(node+1,node+n+1,cmp);
	while(p--){
		int ans=0;
		cin>>ss1>>ss2;
		int l1=ss1.size();
		string kk="";
		for(int i=0;i<=n;i++){
			if(node[i].l>l1) break;
			for(int j=0;j<l1;j++){
				for(int k=0;k<node[i].l;k++){
					if(node[i].s1[k]!=ss1[j+k]){
						break;
					}
					if(k==node[i].l-1){
						kk="";
						for(int q=0;q<l1;q++){
							if(q<j) kk+=ss1[q];
							else if(q>(j+k)) kk+=ss1[q];
							else kk+=node[i].s2[q-j];
						}
//						cout<<j<<" "<<k<<endl;
//						cout<<kk<<" "<<ss2<<endl;
						if(kk==ss2) ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 



