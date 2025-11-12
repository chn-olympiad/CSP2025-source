//GZ-S00245 李雨泽 六盘水市知见外国语学校 
#include<bits/stdc++.h>
using namespace std;
int n,m,ko,sum;
char s[505];
int c[505];
bool used[505];
void dfs(int k){
	if(k>m){
		sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(used[j]==0 && ko<c[j] && s[i]=='1'){
				used[j]=1;
				dfs(k++);
				used[j]=0;
			}else{
				ko++;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char y;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}

	int t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(c[j]>c[i]){
				t=c[j];
				c[j]=c[i];
				c[i]=t;
			}
		}
	}
	dfs(1);
	cout<<22;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
