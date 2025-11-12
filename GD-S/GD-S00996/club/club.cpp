#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int m[100001][4];
int k[100001];
bool cmp(int x,int y)
{
	return x<y;
}
void work()
{
	int n;int nump=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			cin>>m[i][j];
		}
	}
	int num1=0,num2=0,num3=0;
	for(int i=1;i<=n;i++) {
		if(m[i][1]>=m[i][2]&&m[i][1]>=m[i][3]) {
			num1++;a[num1]=i;nump+=m[i][1];
			continue;
		}
		if(m[i][2]>=m[i][1]&&m[i][2]>=m[i][3]) {
			num2++;b[num2]=i;nump+=m[i][2];
			continue;
		}
		if(m[i][3]>=m[i][1]&&m[i][3]>=m[i][2]) {
			num3++;c[num3]=i;nump+=m[i][3];
			continue;
		}
	}
	//cout<<num1<<" "<<num2<<" "<<num3<<endl;
	int yu=n/2;
	if(num1>yu) {
		for(int i=1;i<=num1;i++) {
			k[i]=min(m[a[i]][1]-m[a[i]][2],m[a[i]][1]-m[a[i]][3]);
		}
		sort(k+1,k+1+num1,cmp);
		for(int i=1;i<=num1-(n/2);i++) {
			nump-=k[i];
		}
		cout<<nump<<endl;
		return;
	}
	if(num2>yu) {
		for(int i=1;i<=num2;i++) {
			k[i]=min(m[b[i]][2]-m[b[i]][1],m[b[i]][2]-m[b[i]][3]);
		}
		sort(k+1,k+1+num2,cmp);
		for(int i=1;i<=num2-(n/2);i++) {
			nump-=k[i];
		}
		cout<<nump<<endl;
		return;
	}
	if(num3>yu) {
		for(int i=1;i<=num3;i++) {
			k[i]=min(m[c[i]][3]-m[c[i]][2],m[c[i]][3]-m[c[i]][1]);
		}
		sort(k+1,k+1+num3,cmp);
		for(int i=1;i<=num3-(n/2);i++) {
			nump-=k[i];
		}
		cout<<nump<<endl;
		return;
	}
	cout<<nump<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t) {
		work();
		t--;
	}
	return 0;
}

