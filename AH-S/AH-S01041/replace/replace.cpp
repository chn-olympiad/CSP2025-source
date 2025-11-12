#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string x1,x2;
	string s1,s2;
	int l;
}a[200005];
string q1,q2;
string e1,e2;
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x1>>a[i].x2;
		int len=a[i].x1.size();
		for(int j=0;j<len;j++){
			if(a[i].x1[j]!=a[i].x2[j]){
				for(int t=len-1;t>=j;t--){
					if(a[i].x1[t]!=a[i].x2[t]){
						for(int g=j;g<=t;g++){
							a[i].s1=a[i].s1+a[i].x1[g];
							a[i].s2=a[i].s2+a[i].x2[g];
						}
						a[i].l=a[i].s1.size();
						break;
					}
				}
				break;
			}
		}
	}
//	cout<<a[1].s1;
	while(q--){
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=q1.size();
		ans=0;
		e1.clear(),e2.clear();
		for(int j=0;j<len;j++){
			if(q1[j]!=q2[j]){
				for(int t=len-1;t>=j;t--){
					if(q1[t]!=q2[t]){
						for(int g=j;g<=t;g++){
							e1=e1+q1[g];
							e2=e2+q2[g];
						}
						break;
					}
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].s1==e1&&a[i].s2==e2){
				ans++;
			}
		}	
		printf("%d\n",ans);
	}
	return 0;
}
