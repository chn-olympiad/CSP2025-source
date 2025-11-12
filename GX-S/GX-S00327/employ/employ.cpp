#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[501];
long long ans;
string s;

bool cmp(int x,int y){
	return x<y;
}
void jian(){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(sum2>=num[i]){
			sum2++;
		}else{
			if(s[i-1]=='0'){
				sum2++;
			}else{
				sum1++;
			}
		}
		if(sum1>=m){
			ans++;
		}
	}
}
void change(int x){
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n,cmp);
	jian();
	for(int i=n-1;i>=1;i--){
		change(i);
	}
	cout<<ans;
	return 0;
}
