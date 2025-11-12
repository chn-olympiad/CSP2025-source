#include<bits/stdc++.h>
using namespace std;
string s;
int len,n,num[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//别注释freopen！
	//多测要清空！
	//做完检查！
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	if(len==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n++]=s[i]-'0';
		}
	}
	sort(num,num+n,cmp);
	for(int i=0;i<n;i++) printf("%d",num[i]);
	return 0;
}
//我在这卡了0.5h就因为把这代码放错文件夹了awa 
//done on 8:59
