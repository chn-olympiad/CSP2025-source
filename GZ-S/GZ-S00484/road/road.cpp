//GZ-S00484 贵阳市新世界学校 陶元铀
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[600],b[600],cnt,tmp,cnt1,tmp1,sum=0,tyy=0,lixiang=0;
string s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=0;i<=n+1;++i){
		int sum=0,tyy=0;
		for(int j=1;j<=n;++j){
			cnt=a[i];
			tmp=a[j];
			a[i]=a[j];
			a[j]=cnt;
			if(s[i]=='0'){
				sum+=0;
				tyy++;
			}else if(s[i]=='1'&&tyy<a[i]){
				sum++;
			}else if(s[i]=='1'&&tyy>=a[i]){
				sum+=0;
				tyy++;
			}
			
		}
		if(sum>=m){
			lixiang++;
		}
	}
	cout<<lixiang;
	return 0;
} 
