#include<bits/stdc++.h> 
using namespace std;

long long n,t,s[100005][15],ww[100005];

int Max(int a,int b){
	if(a<b) return b;
	else return a;
} 

int Min(int a,int b){
	if(a<b) return a;
	else return b;
}
int Mid(int a,int b,int c){
	if((a<=b&&a>=c)||(a<=c&&a>=b)) return a;
	else if((b<=a&&b>=c)||(b<=c&&b>=a)) return b;
	else if((c<=a&&c>=b)||(c<=b&&c>=a)) return c;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		int sum=0;
		scanf("%lld",&n);
		int ai=n/2,bi=n/2,ci=n/2;
		for(int j=1;j<=n;j++){
			scanf("%lld%lld%lld",&s[j][1],&s[j][2],&s[j][3]);
			s[j][4]=Max(s[j][1],Max(s[j][2],s[j][3]));
			s[j][5]=Mid(s[j][1],s[j][2],s[j][3]);
			s[j][6]=Min(s[j][1],Min(s[j][2],s[j][3]));
			
			if(s[j][4]==s[j][1]) s[j][7]=1;
			else if(s[j][4]==s[j][2]) s[j][7]=2;
			else if(s[j][4]==s[j][3]) s[j][7]=3;
			if(s[j][5]==s[j][1]) s[j][8]=1;
			else if(s[j][5]==s[j][2]) s[j][8]=2;
			else if(s[j][5]==s[j][3]) s[j][8]=3;
			if(s[j][6]==s[j][1]) s[j][9]=1;
			else if(s[j][6]==s[j][2]) s[j][9]=2;
			else if(s[j][6]==s[j][3]) s[j][9]=3;
		}
		if(n==2){
			if(s[1][7]!=s[2][7]) sum=s[1][4]+s[1][4];
			else{
				if(s[1][4]+s[2][5]>s[2][4]+s[1][5]){
					sum=s[1][4]+s[2][5];
				}else{
					sum=s[2][4]+s[1][5];
				}
			}
		}else {
			for(int j=1;j<=n;j++){
				ww[j]=s[j][1];
			}
			sort(ww+1,ww+n+1);
			for(int j=n;j>n/2;j--){
				sum+=ww[j];
			}
		}
		cout<<sum<<"\n";
	}
	
	
	return 0;
}
