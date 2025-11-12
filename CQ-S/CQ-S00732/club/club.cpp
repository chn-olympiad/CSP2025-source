#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}sum[100005];
bool cmp(node A,node B){
	return max(A.a,max(A.b,A.c))>max(B.a,max(B.b,B.c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,s[3],num=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>sum[i].a>>sum[i].b>>sum[i].c;
		}
		sort(sum+1,sum+n+1,cmp);
		for (int i=1;i<=n;i++){
			int x=max(sum[i].a,max(sum[i].b,sum[i].c));
			if(sum[i].a=x){
				if(s[1]<=n/2){
					s[1]++;
					num+=sum[i].a;
				}else{
					if(sum[i].b>sum[i].c&&s[2]<=n/2){
						s[2]++;
						num+=sum[i].b;
					}else{
						s[3]++;
						num+=sum[i].c;
					}
				}
			}
			if(sum[i].b=x){
				if(s[2]<=n/2){
					s[2]++;
					num+=sum[i].a;
				}else{
					if(sum[i].a>sum[i].c&&s[1]<=n/2){
						s[1]++;
						num+=sum[i].a;
					}else{
						s[3]++;
						num+=sum[i].c;
					}
				}
			}
			if(sum[i].c=x){
				if(s[3]<=n/2){
					s[3]++;
					num+=sum[i].a;
				}else{
					if(sum[i].a>sum[i].b&&s[1]<=n/2){
						s[1]++;
						num+=sum[i].a;
					}else{
						s[2]++;
						num+=sum[i].b;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
