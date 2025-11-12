#include<bits/stdc++.h>
using namespace std;
long long a[100000000000];
char ch[1000];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m=0,p=0,v=0;
	int count=0;
	cin>>n>>m;
	gets(ch);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int q=0;q<n;q++){
		for(int o=0;o<n;o++){
			v=a[q];
			a[q]=a[o];
			a[o]=v;
			v=0;
		for(int i=0;i<n;i++){
			if(ch[i]=='0'){
				a[i]=0;
			for(int j=i+1;j<n-i-1;j++){
					a[j]-=1;
				}
			}else if(ch[i]=='1'){
				count++;
			}
		for(int w=0;w<n;w++){
			if(a[w]==0){
				a[w]=a[w+1];
				a[w+1]=0;
			}
		}
	}	
			if(count>=m){
				p++;
			}
		}
	}
	cout<<p;
	return 0;
}

