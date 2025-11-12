#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],b[N],ze;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) ze++;
	} 
	int len=strlen(s),sum=0;
	for(int i=0;i<len;i++){
		b[i]=sum;
		if(s[i]=='0') sum++;
	}
	if(n-sum<m) printf("0\n");
	else if(sum==0){
		if(n-ze<m) printf("0\n");
	}else if(sum==n){
		printf("0\n");
	}else if(m==n){
		if(sum>0) printf("0\n");
	}
	
	return 0;
}

