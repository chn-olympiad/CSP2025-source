#include<bits/stdc++.h>
using namespace std;
int t,stu[100001][4],c[4][100001];
long long s;
int sok(int a[4][100001],int k,int x,int op[100001][4]){
	int next[100001];
	for (int i=1;i<=a[k][0];i++){
		int ox=a[k][i];
		next[i]=op[ox][k]*2+min(op[ox][1],min(op[ox][2],op[ox][3]))-(op[ox][1]+op[ox][2]+op[ox][3]);
	}
	sort(next+1,next+1+a[k][0]);
	int co=0; 
	for (int i=1;i<=a[k][0]-x;i++)
	    co+=next[i];
	return co;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int T=1;T<=t;T++){
		memset(c,0,sizeof(c));
		memset(stu,0,sizeof(stu));
		int n;
		s=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
			if (stu[i][1]==max(stu[i][1],max(stu[i][2],stu[i][3])))
			    c[1][++c[1][0]]=i;
			if (stu[i][2]==max(stu[i][1],max(stu[i][2],stu[i][3])))
			    c[2][++c[2][0]]=i;
			if (stu[i][3]==max(stu[i][1],max(stu[i][2],stu[i][3])))
			    c[3][++c[3][0]]=i;
			s+=max(stu[i][1],max(stu[i][2],stu[i][3]));
		}
		int co=0;
		if (max(c[1][0],max(c[2][0],c[3][0]))>n/2)
			co=sok(c,(max(c[1][0],max(c[2][0],c[3][0]))==c[1][0])?1:((max(c[1][0],max(c[2][0],c[3][0]))==c[2][0])?2:3),n/2,stu);
		cout<<s-co<<endl;
	}
	return 0;
} 
