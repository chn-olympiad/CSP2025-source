#include<iostream>
#include<algorithm>
using namespace std;
int ans;
struct st{
	int a,b,c;
}i0[100002];
int fm(int a,int b,int c){
	return(a>=b&&a>=c)?1:((b>=a&&b>=c)?2:3);
}
bool sa(st x,st y){
	return x.a>y.a;
}
bool sb(st x,st y){
	return x.b>y.b;
}
bool sc(st x,st y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,i,j,d[4]={0,0,0,0};
		cin>>n;
		j=n;ans=0;
		for(int i=1;i<=n;i++){
			cin>>i0[i].a>>i0[i].b>>i0[i].c;
		}
		sort(i0+1,i0+1+n,sa);
		for(i=1;i<=n&&d[1]<n/2;i++){
			
			if(fm(i0[i].a,i0[i].b,i0[i].c)==1){
				ans+=i0[i].a;
				d[1]++;
				i0[i].b=0;i0[i].c=0;
				j--;
			}
			
			i0[i].a=0;
			
			
		}
		sort(i0+1,i0+1+n,sb);
		for(i=1;i<=n&&d[2]<n/2;i++){
			
			if(fm(i0[i].a,i0[i].b,i0[i].c)==2){
				ans+=i0[i].b;
				d[2]++;
				i0[i].c=0;
				j--;
			}
			i0[i].b=0;
			
			
		}
		sort(i0+1,i0+1+n,sc);
		for(i=1;i<=j;i++){
			ans+=i0[i].c;
		}
		
		
		
		
			cout<<ans<<endl;
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
