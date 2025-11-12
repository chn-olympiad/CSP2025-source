#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char a[N];
int b[N],cnt=0;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;++i){
	   a[i]=s[i];
	}	
	for(int i=0;i<lens;++i){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
		   	b[i]=a[i]-'0';
		   	cnt++;
			
		}
	}
	sort(b,b+lens,cmp);
	for(int i=0;i<cnt;++i){
	    cout<<b[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}