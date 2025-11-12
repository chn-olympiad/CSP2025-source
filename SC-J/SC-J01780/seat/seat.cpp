#include<bits/stdc++.h>
using namespace std;

const int N=3e3;

int in(){
	int t=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return t*k;
}

void out(int x){
	if(x<0)x=-x,putchar('-');
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10);putchar(x%10+'0');
}

//struct ode{
//	int id,val;
//}
int a[N];

int n,m;

bool cmp(int x,int y){
	return x>y;
}

int erfen(int l,int r,int tmp){
	int mid=(l+r)>>1;
	while(l<=r){
		int mid=(l+r)>>1;
		//out<<l<<" "<<r<<" "<<mid<<endl;
		if(a[mid]<tmp)r=mid;
		else if(a[mid]>tmp)l=mid+1;
		else if(a[mid]==tmp)return mid;
		
	}
	return mid;	
}

//bool cmp(node x,node y){
//	if(x.val==y.val)return x.id<y.id;
//	return x.val<y.val;
//}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	n=in(),m=in();
	int tmp=0;
	for(int i=1;i<=n*m;i++){
		a[i]=in();
		//a[i].id=i;
	}
	tmp=a[1];
	//cout<<tmp<<endl;
	sort(a+1,a+n*m+1,cmp);
	int ans=erfen(1,n*m,tmp);
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
//	cout<<ans<<endl;
	int y=ans/n+(ans%n!=0),x=0;
	if(y%2==1){
		x=ans%n;
		if(x==0){
			x=n;
		}
	}else{
		x=ans%n;
		if(x==0){
			x=1;
		}
		x=n-x+1;		
	}
	out(y);printf(" ");
	out(x);
	//cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/