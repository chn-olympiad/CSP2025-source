#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][4],n,t;
struct node{
	int a[4];
	int mv[4][4];
}stu[maxn],A[maxn],B[maxn],C[maxn];
int cnt_A,cnt_B,cnt_C,ans;

bool cmp_A(node x,node y){
	if(max(x.mv[1][2],x.mv[1][3])>max(y.mv[1][2],y.mv[1][3]))return 1;
	return 0;
}
bool cmp_B(node x,node y){
	if(max(x.mv[2][1],x.mv[2][3])>max(y.mv[2][1],y.mv[2][3]))return 1;
	return 0;
}
bool cmp_C(node x,node y){
	if(max(x.mv[3][1],x.mv[3][2])>max(y.mv[3][1],y.mv[3][2]))return 1;
	return 0;
}

void set_mv(int i){
	for(int j=1;j<=3;j++){
		for(int k=1;k<=3;k++){
			stu[i].mv[j][k]=stu[i].a[k]-stu[i].a[j];
		}
	}
}
void push_stu(int i){
	int max_a=max(max(stu[i].a[1],stu[i].a[2]),stu[i].a[3]);
	if(max_a==stu[i].a[1]){
		A[++cnt_A]=stu[i];	ans+=stu[i].a[1];
		return;
	}
	if(max_a==stu[i].a[2]){
		B[++cnt_B]=stu[i];	ans+=stu[i].a[2];
		return;
	}
	if(max_a==stu[i].a[3]){
		C[++cnt_C]=stu[i];	ans+=stu[i].a[3];
		return;
	}
}

void sol_A(){
	sort(A+1,A+cnt_A+1,cmp_A);
	int m=cnt_A-n/2;
	for(int i=1;i<=m;i++){
		ans+=max(A[i].mv[1][2],A[i].mv[1][3]);
	}
	return;
}
void sol_B(){
	sort(B+1,B+cnt_B+1,cmp_B);
	int m=cnt_B-n/2;
	for(int i=1;i<=m;i++){
		ans+=max(B[i].mv[2][1],B[i].mv[2][3]);
	}
	return;
}
void sol_C(){
	sort(C+1,C+cnt_C+1,cmp_C);
	int m=cnt_C-n/2;
	for(int i=1;i<=m;i++){
		ans+=max(C[i].mv[3][2],C[i].mv[3][1]);
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);//cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",stu[i].a+1,stu[i].a+2,stu[i].a+3);//cin>>stu[i].a[1]>>stu[i].a[2]>>stu[i].a[3];
			set_mv(i);
			push_stu(i);
		}
		if(cnt_A>n/2){
			sol_A();
		}else if(cnt_B>n/2){
			sol_B();
		}else if(cnt_C>n/2){
			sol_C();
		}
		cout<<ans<<endl;
		cnt_A=cnt_B=cnt_C=0;
		ans=0;
	}
	return 0;
}

