#include<iostream>
#include<algorithm>
using namespace std;
struct aa{
	int a,id;	
}a[10005];
bool cmp(aa b,aa c){
	return b.a>c.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;a[i].id=i,i++)
		cin>>a[i].a;
	sort(a+1,a+1+n*m,cmp); 
	int i=1,j=1,ch=1;
	for(int k=1;i<=n*m;i+=ch,k++){
		if(i==n+1&&ch==1)
			i=n,ch=-1,j++;
		if(i==0&&ch==-1)
			i=1,ch=1,j++;
		if(a[k].id==1){
			cout<<j<<' '<<i;
			return 0;
		}
		
	}
} 
