//GZ-S00410 清镇市博雅实验学校 许秉轩 
#include<bits/stdc++.h>
using namespace std;
int n,m,len,cnt,ckm;
string s;
int a[550],c[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]==(0+'0')){
			
		}else{
			cnt++;
			if(c[i]<=cnt){
				cnt++;
			}else{
				cnt=0;
				ckm++;
			}
		}
		
	}
	return 0;
}
