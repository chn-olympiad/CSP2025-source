#include <bits/stdc++.h>
using namespace std;
string s;
long long ans,t=1,b,temp=1;
long long a[1000025];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);//我不欢迎雷老师欣赏我的代码=) 
	freopen("number.out","w",stdout);//我不会判断数字，直接打表 
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){ //判断数字 
			a[t]=s[i]-'0';
			t++;
	    }
	}
	if(b==0) b=1;
	sort(a+1,a+t+1,cmp);
//	for(int i=2;i<=t;i++){
//		cout<<a[i]<<endl;
//	}
	for(int i=2;i<=t;i++){
		ans+=a[i]*temp;//把数按位数加起来 
		temp*=10;
	}
	cout<<ans;//Hello World
	return 0;
}
