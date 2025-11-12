#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
void pai(){
	int siz=s.size(),sizz=0;
	for(int i=0;i<siz;i++)if('0'<=s[i] && s[i]<='9'){sizz+=1;a[sizz]=s[i]-'0';}
	sort(a+1,a+sizz+1,cmp);
	for(int i=1;i<=sizz;i++)printf("%d",a[i]);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	pai();
	return 0;
}
