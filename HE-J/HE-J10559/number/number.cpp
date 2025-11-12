#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int b[N],cnt=1,tmpi;
void px(int x,int y){
	for(int i=y;i>=x;i--){
		tmpi=i;
		while(b[tmpi]>b[tmpi-1]&&tmpi>1){
			int tmp=b[tmpi-1];
			b[tmpi-1]=b[tmpi];
			b[tmpi]=tmp;
			tmpi--;
		}
		px(tmpi+1,cnt);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt]=a[i]-48;
			cnt++;
		}
    }
    cnt--;
	px(1,cnt);
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
} 
