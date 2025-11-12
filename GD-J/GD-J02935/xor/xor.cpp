#include <iostream>
using namespace std;
const int MAXN=5*1e5+5;
int a[MAXN];
int s[MAXN];
bool f[MAXN];
int main(){
	
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i-1==0){
			s[i]=a[i];
		}else{
			s[i]=s[i-1]^a[i];
		}
		if(a[i]==k){
			f[i]=true;
			ans++;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;(j+i-1)<=n;j++){
			int temp;
			if(j-1==0){
				temp=s[j+i-1];
			}else{
				temp=s[j+i-1]^s[j-1];
			}
			if(temp==k){
				bool pan=true;
				for(int q=j;q<=(j+i-1);q++){
					if(f[q]==true){
						pan=false;
						break;
					}
				}
				if(pan==false){
					continue;
				}
				for(int q=j;q<=(j+i-1);q++){
					f[q]=true;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout); 
	
	
	return 0;
}
