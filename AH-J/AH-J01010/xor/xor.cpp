#include<bits/stdc++.h>
using namespace std;
int n,k,x1,num1;
int ansk[30];
struct node{
	int num;
	int w;
	int q;
}a[500005];
int s[550005][30];
int jz(int i){
	int x=1,num=a[i].num,sum=0;
	if (num==0)
		x=1,s[i][1]=0;
	while(num>0){
		s[i][x]=num%2;
		num/=2;
		x++;
		sum++;
	}
	x--;
	for (int j=1;j+j<=x;j++){
		
		swap(s[i][j],s[i][x-j+1]);
	}
	for (int j=1;j<=x;j++)
		cout<<s[i][j];
		cout<<endl;
	return sum;
}
int yh(int x){
	if (a[x].w>a[x+1].w){
		int m=a[x].w;
		for (int i=1;i<=m;i++)
			if (s[x][i]!=s[x+1][i])
				s[x][i]=1;
			else
				s[x][i]=0;
	}
	else{
		int m=a[x+1].w;
		for (int i=1;i<=m;i++)
			if (s[x][i]!=s[x+1][i])
				s[x+1][i]=1;
			else
				s[x+1][i]=0;
	}
	return 0;
}
int check(int x){
	int f=1,l=a[x].w;
	if (l!=x1)
		f=0;
	while(l>0){
		if (s[x][l]!=ansk[l]){
			f=0;
			break;
		}	
		l--;
	}
	return f;	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i].num;
	long long ans=0;
	x1=1,num1=k;
	while(num1>0){
		ansk[x1]=num1%2;
		num1/=2;
		x1++;
	}
	x1--;
	for (int j=1;j<=x1;j++)
		swap(ansk[j],ansk[x1-j+1]);
	for (int i=1;i<=n;i++){
		a[i].w=jz(i);
		if (check(i)){
			a[i].q=1;
			ans++;
		}
	}
	while(n>0){
		for (int i=1;i<=n;i++){
			if (a[i].q||a[i+1].q)
				continue;
			yh(i);
			if (check(i)){
				a[i].q=1,a[i+1].q=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
