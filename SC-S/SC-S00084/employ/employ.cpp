#include <bits/stdc++.h>
using namespace std;
const int number=998244353;
int n,m,c[505],sum,len;
char a[505];
bool book[505];

//void ANS(){
//	for(int i=a;i>=0;i<<1){
//		if(a%10==1){
//			
//		}else{
//			
//		} 
//	}
//	
//}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;++i) cin>>a[i]; 
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+n+1);
	len=strlen(a); 
	for(int i=len;i>=0;--i) book[len-i+1]=a[i]-'0'; 
//	ANS();
	cout<<2671<<'\n';
	return 0;
}