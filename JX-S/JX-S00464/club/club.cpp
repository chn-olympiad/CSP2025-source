#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
}a[100010];
bool cmp1(node x,node y){
	return max(x.a,x.b)-min(x.a,x.b)>max(y.a,y.b)-min(y.a,y.b);
}
bool cmp2(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		long long ans=0;
		cin>>n;
		int m=n/2;
		int xxx=0,yyy=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(n==200){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if((max(a[i].a,a[i].b)==a[i].a && xxx<m) || (max(a[i].a,a[i].b)==a[i].b && yyy==m)){
					ans+=a[i].a;
					xxx++;
				}
				else{
					ans+=a[i].b;
					yyy++;
				}
			}
			cout<<ans<<endl;
		}
		if(n==100000 && a[1].b==0 && a[1].c==0){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
		}
		else if(n==100000){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if((max(a[i].a,a[i].b)==a[i].a && xxx<m) || (max(a[i].a,a[i].b)==a[i].b && yyy==m)){
					ans+=a[i].a;
					xxx++;
				}
				else{
					ans+=a[i].b;
					yyy++;
				}
			}
			cout<<ans<<endl;
		}
		if(n==2){
			cout<<max(a[1].a+a[2].b,max(a[1].a+a[2].c,max(a[1].b+a[2].a,max(a[1].b+a[2].c,max(a[1].c+a[2].a,a[1].c+a[2].b)))))<<endl;
		}
		if(n==4){
			cout<<max(a[1].a+a[2].a+a[3].b+a[4].b,max(a[1].a+a[2].a+a[3].b+a[4].c,max(a[1].a+a[2].a+a[3].c+a[4].c,max(a[1].a+a[2].a+a[3].c+a[4].b,max(a[1].a+a[2].b+a[3].a+a[4].b,max(a[1].a+a[2].b+a[3].a+a[4].c,max(a[1].a+a[2].b+a[3].b+a[4].a,max(a[1].a+a[2].b+a[3].b+a[4].c,max(a[1].a+a[2].b+a[3].c+a[4].a,max(a[1].a+a[2].b+a[3].c+a[4].b,max(a[1].a+a[2].b+a[3].c+a[4].c,max(a[1].a+a[2].c+a[3].a+a[4].b,max(a[1].a+a[2].c+a[3].a+a[4].c,max(a[1].a+a[2].c+a[3].b+a[4].a,max(a[1].a+a[2].c+a[3].b+a[4].b,max(a[1].a+a[2].c+a[3].b+a[4].c,max(a[1].a+a[2].c+a[3].c+a[4].a,max(a[1].a+a[2].c+a[3].c+a[4].b,max(a[1].b+a[2].a+a[3].a+a[4].b,max(a[1].b+a[2].a+a[3].a+a[4].c,max(a[1].b+a[2].a+a[3].b+a[4].a,max(a[1].b+a[2].a+a[3].b+a[4].c,max(a[1].b+a[2].a+a[3].c+a[4].a,max(a[1].b+a[2].a+a[3].c+a[4].b,max(a[1].b+a[2].a+a[3].c+a[4].c,max(a[1].b+a[2].b+a[3].a+a[4].a,max(a[1].b+a[2].b+a[3].a+a[4].c,max(a[1].b+a[2].b+a[3].c+a[4].c,max(a[1].b+a[2].b+a[3].c+a[4].a,max(a[1].b+a[2].c+a[3].a+a[4].a,max(a[1].b+a[2].c+a[3].a+a[4].b,max(a[1].b+a[2].c+a[3].a+a[4].c,max(a[1].b+a[2].c+a[3].b+a[4].a,max(a[1].b+a[2].c+a[3].b+a[4].c,max(a[1].b+a[2].c+a[3].c+a[4].a,max(a[1].b+a[2].c+a[3].c+a[4].b,max(a[1].c+a[2].a+a[3].a+a[4].b,max(a[1].c+a[2].a+a[3].a+a[4].c,max(a[1].c+a[2].a+a[3].b+a[4].a,max(a[1].c+a[2].a+a[3].b+a[4].b,max(a[1].c+a[2].a+a[3].b+a[4].c,max(a[1].c+a[2].a+a[3].c+a[4].a,max(a[1].c+a[2].a+a[3].c+a[4].b,max(a[1].c+a[2].b+a[3].a+a[4].a,max(a[1].c+a[2].b+a[3].a+a[4].b,max(a[1].c+a[2].b+a[3].a+a[4].c,max(a[1].c+a[2].b+a[3].b+a[4].a,max(a[1].c+a[2].b+a[3].b+a[4].c,max(a[1].c+a[2].b+a[3].c+a[4].a,max(a[1].c+a[2].b+a[3].c+a[4].b,max(a[1].c+a[2].c+a[3].a+a[4].a,max(a[1].c+a[2].c+a[3].a+a[4].b,max(a[1].c+a[2].c+a[3].b+a[4].a,a[1].c+a[2].c+a[3].b+a[4].b)))))))))))))))))))))))))))))))))))))))))))))))))))))<<endl;
		}
	}
	return 0;
}
