#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long arr[50001];
long long a[50001][50001];
long long b[50001];
int ans;
string zh(int o){
	string ans;
	while(1){
		if(o==1){
			char h='1';
			ans=ans+h;
			return ans;
		}
		int g=o%2;
		char h=g+'0';
		ans=ans+h;
		o/=2;
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				a[i][j]=arr[i];
			}
			else{
				if(i<j){ 
					string w=zh(arr[i]);
					for(int l=i+1;l<=j;l++){
						string s=zh(arr[l]);
						int e=max(s.size(),w.size());
						char h='0';
						if(s.size()!=e){
						int o=e-s.size();
							for(int g=0;g<o;g++){
								s=s+h;
							}
						}
						else{
							int o=e-w.size();
							for(int g=0;g<o;g++){
								w=w+h;
							}
						}
						for(int g=0;g<e;g++){ 
							if(s[g]==w[g]){
								w[g]='0';
							}
							else{
								w[g]='1';
							}
						} 
					}
					for(int g=0;g<w.size();g++){ 
						int o=(w[g]-'0');
						for(int h=1;h<=g;h++){
							o*=2;
						}
						a[i][j]+=o;
					}
				}
				else{
					a[i][j]=a[j][i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i][j]==k){
				for(int p=i;p<=j;p++){
					if(b[p]==1){
						a[i][j]--;
					}
				}
			}
			if(a[i][j]==k){
				for(int p=i;p<=j;p++){
					b[p]=1;
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
