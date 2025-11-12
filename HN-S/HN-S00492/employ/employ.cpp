#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],f,mn,ans=1,l;
string s;
int jc(int x){
	long long r=1;
	for(int i=2;i<=x;i++){
		r=(r*i)%998244353;
	}
	return (int)(r);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		if(f){
			printf("0");
		}else{
			printf("%d",jc(n));
		}
		return 0;
	}
	if(!f){
		printf("%d",jc(n));
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1){
		for(int i=1,ss;i<=n;i++){
			if(s[i-1]=='1'){
				ss=0;
				for(int j=i;j<=n;j++){
					if(a[j]>0){
						ss++;
					}
				}
				if(a[i]>0){
					printf("%d",jc(ss));
					return 0;
				}else{
					if(ss>0){
						printf("%d",jc(ss));
					}else{
						printf("0");
					}
					return 0;
				}
			}else{
				for(int j=i+1;j<=n;j++){
					a[j]--;
				}
			}
		}
		printf("0");
		return 0;
	}
	for(int i=1,ss;i<=n;i++){
		ss=0;
		if(mn>=m){
			ans=(ans*(n-i+1))%998244353;
		}
		if(s[i-1]=='1'){
			for(int j=i;j<=n;j++){
				if(a[j]>0){
					ss++;
				}
			}
			if(a[i]>0){
				ans=(ans*ss)%998244353;
				mn++;
			}else{
				if(ss>0){
					int o=0;
					for(int j=i+1;j<=n;j++){
						if(a[j]>0){
							if(a[j]<a[o]){
								o=j;
							}
						}
					}
					swap(a[i],a[o]);
					ans=(ans*ss)%99824353;
					mn++;
				}else{
					if(mn>=m){
						printf("%d",ans);
						return 0;
					}
					printf("0");
					return 0;
				}
			}	
		}else{
			for(int j=i+1;j<=n;j++){
				a[j]--;
			}
		}
	}
	if(mn<m){
		printf("0");
		return 0;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
