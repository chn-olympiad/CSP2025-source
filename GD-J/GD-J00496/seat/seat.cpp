#include <iostream>
#include <algorithm>
using namespace std;
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
const int N=110;
int n,m;
struct node{
	int index,data;
}a[N];
bool cmp(node a,node b){
	return a.data>b.data;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++){
		a[i].data=read();
		a[i].index=i;
	}
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i].data<<" ";
	}
	cout<<endl;*/
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].index==1){
			cnt=i;
			break;
		}
	}
	int c=cnt/n,r=1;
	//cout<<cnt<<endl;
	if(cnt%2!=0){
		c++;
	}else{
		r=n;
		cout<<c<<" "<<r;
		return 0;
	}
	if(c%2==0){
		r=n-(cnt%n)+1;
	}else{
		r=cnt%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
