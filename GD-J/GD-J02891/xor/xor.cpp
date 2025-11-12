#include<cstdio>
int n,k,s[205][205],a[205],ans;
bool b[205],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	s[0][0]=a[0];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			s[i][j]=s[i][j-1]^a[j];
			if(s[i][j]==k){
				for(int g=i;g<=j;g++){
					if(b[g])flag=1;
				}
				if(flag){
					flag=0;
				}
				else{
					for(int g=i;g<=j;g++){
						b[g]=1;
					}
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
