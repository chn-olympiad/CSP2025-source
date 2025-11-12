#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,a[100010][10],sat,num1,num2,num3,vis[100010];
struct yyy{
	int id;
	int love;
}b1[100010],b2[100010],b3[100010];
struct xxx{
	int ct;
	int sum;
	int id;
	//int qc;
}ppp[100010];

void init(){
	n=sat=num1=num2=num3=0;
	for(int i=1;i<=100000;i++){
		for(int j=1;j<=5;j++){
			a[i][j]=0;
			vis[i]=0;
		}
		b1[i].id=0;b2[i].id=0;b3[i].id=0;
		b1[i].love=0;b2[i].love=0;b3[i].love=0;
		ppp[i].ct=0,ppp[i].id=0,ppp[i].sum=0;
	}
}

int tmax(int i,int j,int k){
	return max(i,max(j,k));
}

bool cmp(yyy u,yyy v){
	return u.love>v.love;
}

bool cmp2(xxx u,xxx v){
	if(u.ct!=v.ct) return u.ct>v.ct;
	else return u.sum>v.sum;
	//return u.sum>v.sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

	cin >> T;
	while(T--){
		init();
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b1[i].id=i;b1[i].love=a[i][1];
			b2[i].id=i;b2[i].love=a[i][2];
			b3[i].id=i;b3[i].love=a[i][3];
			ppp[i].ct=2*tmax(a[i][1],a[i][2],a[i][3])-a[i][1]-a[i][2]-a[i][3];
			ppp[i].sum=a[i][1]+a[i][2]+a[i][3];
			ppp[i].id=i;
			//ppp[i].qc=(ppp[i].sum/3-a[i][1])*(ppp[i].sum/3-a[i][1])+(ppp[i].sum/3-a[i][2])*(ppp[i].sum/3-a[i][2])+(ppp[i].sum/3-a[i][3])*(ppp[i].sum/3-a[i][3]);
		}
		sort(b1+1,b1+n+1,cmp);
		sort(b2+1,b2+n+1,cmp);
		sort(b3+1,b3+n+1,cmp);
		sort(ppp+1,ppp+n+1,cmp2);
		//for(int i=1;i<=n;i++) cout << ppp[i].id << ' ';
		
		
		for(int i=1;i<=n;i++){
			//cout << sat << '\n';
			int j=ppp[i].id;
			int kkk=0,lll=0,mmm=0;
			if(num1+1<=n/2 && !vis[j]) kkk=a[j][1];
			if(num2+1<=n/2 && !vis[j]) lll=a[j][2];
			if(num3+1<=n/2 && !vis[j]) mmm=a[j][3];
			if(tmax(kkk,lll,mmm)==kkk){
				sat+=kkk,num1++,vis[j]=1;
				continue;
			}
			if(tmax(kkk,lll,mmm)==lll){
				sat+=lll,num2++,vis[j]=1;
				continue;
			}
			if(tmax(kkk,lll,mmm)==mmm){
				sat+=mmm,num3++,vis[j]=1;
				continue;
			}
			//cout << sat << '\n';
		}
		
		cout << sat << '\n';
	}
	/*
	1
	10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522


150176
	*/
	return 0;
}

