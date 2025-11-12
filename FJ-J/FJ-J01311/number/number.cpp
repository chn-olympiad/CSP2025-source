#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int a[N],m,n;
string s;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();//相对较方便； 
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';//强行转成int； 
			m++;//统计数字的个数； 
		}
	}
	sort(a,a+n,cmp);//最大的数字； 
	for(int i=0;i<m;i++){
		cout<<a[i];
	}/*
	直接输出； 
	*/
	return 0;
}

