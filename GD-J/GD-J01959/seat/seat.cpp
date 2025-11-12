#include<iostream>
#include<algorithm>
using namespace std;
int n,m,me,a[105],idx;
void write(int a){
	if(a<0) putchar('-'),a*=-1;
	if(a>9) write(a/10);
	putchar(a%10+'0');
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	me=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==me){
			idx=i;
			break;
		}
	}
	idx--;
	write(idx/n+1);
	putchar(' ');
	if((idx/n+1)%2) write(idx%n+1);
	else write(m-idx%n);
	return 0;
}
