#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
//T1 :100pts 
//注意 freopen用了吗 ll要开吗 N大小够吗
string a;
int f[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			f[++cnt]=a[i]-'0';
		}
	}
	sort(f+1,f+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		std::cout<<f[i];
	}
	return 0;
}
/*  u_u  */
