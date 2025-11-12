#include<bits/stdc++.h>
//大bits/stdc++.h，是我的家乡 
using namespace std;
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	map<int,int>m;
	cin>>a;
	//超级拆解 
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')m[a[i]-'0']++;
	}
	 
	if(a.size()==1&&m[0]){
		cout<<0;
		return 0;
	}
	//超级拼装 
	for(int i=9;i>=0;i--){
		for(int j=0;j<m[i];j++)
			cout<<i;
	}
	return 0;
} 

//搞了半天原来要自己拼 

//下次还填非常简单 