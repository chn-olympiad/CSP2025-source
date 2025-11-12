#include<bits/stdc++.h>
using namespace std;
int n,t;
struct stu{
	int a,b,c;
	int mx,mi;
}s[100005];

bool cmp(stu k,stu l){
	return k.mx > l.mx;
}
int sums[20005][4][4];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		
		cin>>n;
		int ji=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			sums[i][1][0]=s[i].a;
			sums[i][2][0]=s[i].b;
			sums[i][3][0]=s[i].c;
			
			if(s[i].a >= s[i].b && s[i].a >= s[i].c){
				s[i].mx=s[i].a;
				s[i].mi=1;
			}
			else if(s[i].b >= s[i].a && s[i].b >= s[i].c){
				s[i].mx=s[i].b;
				s[i].mi=2;
			}
			else{
				s[i].mx=s[i].c;
				s[i].mi=3;
			}
		}
		sort(s+1,s+n+1,cmp);
//		cout<<"´íÎóÅÅ²é"<<endl;
		
		for(int i=1;i<=n;i++){
			if(sums[i-1][1][1] < ji && sums[i-1][1][0] + s[i].a > sums[i][1][0]){
				sums[i][1][0]=sums[i-1][1][0] + s[i].a;
				sums[i][1][1]=sums[i-1][1][1] + 1;
				sums[i][1][2]=sums[i-1][1][2] ;
				sums[i][1][3]=sums[i-1][1][3] ;
			}
			if(sums[i-1][2][1] < ji && sums[i-1][2][0] + s[i].a > sums[i][1][0]){
				sums[i][1][0]=sums[i-1][2][0] + s[i].a;
				sums[i][1][1]=sums[i-1][2][1] + 1;
				sums[i][1][2]=sums[i-1][2][2] ;
				sums[i][1][3]=sums[i-1][2][3] ;
			}
			if(sums[i-1][3][1] < ji && sums[i-1][3][0] + s[i].a > sums[i][1][0]){
				sums[i][1][0]=sums[i-1][3][0] + s[i].a;
				sums[i][1][1]=sums[i-1][3][1] + 1;
				sums[i][1][2]=sums[i-1][3][2] ;
				sums[i][1][3]=sums[i-1][3][3] ;
			}
			
			
			
			if(sums[i-1][1][2] < ji && sums[i-1][1][0] + s[i].b > sums[i][2][0]){
				sums[i][2][0]=sums[i-1][1][0] + s[i].b;
				sums[i][2][1]=sums[i-1][1][1] ;
				sums[i][2][2]=sums[i-1][1][2] + 1;
				sums[i][2][3]=sums[i-1][1][3] ;
			}
			if(sums[i-1][2][2] < ji && sums[i-1][2][0] + s[i].b > sums[i][2][0]){
				sums[i][2][0]=sums[i-1][2][0] + s[i].b;
				sums[i][2][1]=sums[i-1][2][1] ;
				sums[i][2][2]=sums[i-1][2][2] + 1;
				sums[i][2][3]=sums[i-1][2][3] ;
			}
			if(sums[i-1][3][2] < ji && sums[i-1][3][0] + s[i].b > sums[i][2][0]){
				sums[i][2][0]=sums[i-1][3][0] + s[i].b;
				sums[i][2][1]=sums[i-1][3][1] ;
				sums[i][2][2]=sums[i-1][3][2] + 1;
				sums[i][2][3]=sums[i-1][3][3] ;
			}
			
			
			
			if(sums[i-1][1][3] < ji && sums[i-1][1][0] + s[i].c > sums[i][3][0]){
				sums[i][3][0]=sums[i-1][1][0] + s[i].c;
				sums[i][3][1]=sums[i-1][1][1] ;
				sums[i][3][2]=sums[i-1][1][2] ;
				sums[i][3][3]=sums[i-1][1][3] + 1;
			}
			if(sums[i-1][2][3] < ji && sums[i-1][2][0] + s[i].c > sums[i][3][0]){
				sums[i][3][0]=sums[i-1][2][0] + s[i].c;
				sums[i][3][1]=sums[i-1][2][1] ;
				sums[i][3][2]=sums[i-1][2][2] ;
				sums[i][3][3]=sums[i-1][2][3] + 1;
			}
			if(sums[i-1][3][3] < ji && sums[i-1][3][0] + s[i].c > sums[i][3][0]){
				sums[i][3][0]=sums[i-1][3][0] + s[i].c;
				sums[i][3][1]=sums[i-1][3][1] ;
				sums[i][3][2]=sums[i-1][3][2] ;
				sums[i][3][3]=sums[i-1][3][3] + 1;
			}
			
			
		}
		
		cout<<max(sums[n][1][0] , max(sums[n][2][0],sums[n][3][0]) )<<endl;
	}
	return 0;
} 
