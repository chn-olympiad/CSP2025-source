#include<cstdio>
int n,m,ans;
int s_m[101],s_m_c[101];
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) {
		scanf("%d",&s_m[i]);
		s_m_c[i]=s_m[i];
	}
	for (int i=1;i<=n*m-1;i++){
		for (int j=i+1;j<=n*m;j++){
			if (s_m[j]>s_m[i]){
				int k=s_m[i];
				s_m[i]=s_m[j];
				s_m[j]=k;
			}
		}
	}
	for (int i=1;i<=n*m;i++){
		if (s_m_c[1]==s_m[i]) ans=i;
	}
	if (ans%n==0) c=ans/n;
	else c=ans/n+1;
	if (ans%n==0){
		if (c%2==0) r=1;
		else r=n;
	}
	else {
		if (c%2==0) r=n-ans%n+1;
		else r=ans%n;
	}
	printf("%d%c%d",c,' ',r);
	return 0;
} 
