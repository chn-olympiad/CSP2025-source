#include<bits/stdc++.h>
using namespace std;
int n;
int t;
long long ans;
struct p{
	int a;
	int id=1;
	int maxp[4];//一到三大 
	int maxq[4]={0,1,2,3};
	int max1;
	int max2;
	int max3;
	bool used[4];
	int b;
	int c;
	int cha1;
	int cha2;
//	int dangqianshuanze;
};
p member[200];
bool cmp(p x,p y){
	return x.a>y.a;
}
/*void work1(int x,long long hzx,int num1,int num2,int num3){
	if(num1==100) return;
work(x+1,hzx+member[x].a,num1+1,num2,num3);
}
void work2(int x,long long hzx,int num1,int num2,int num3){
		if(num2==100) return;
work(x+1,hzx+member[x].b,num1,num2+1,num3);
}
void work3(int x,long long hzx,int num1,int num2,int num3){
	if(num1==100) return;
work(x+1,hzx+member[x].c,num1,num2,num3+1);
}*/
void work(int x,long long hzx,int num1,int num2,int num3){
	if(x>200){
		ans=max(ans,hzx);
		return;	
		}
if(num1<100) work(x+1,hzx+member[x].a, num1+1, num2, num3);
if(num2<100) work(x+1,hzx+member[x].b, num1, num2+1, num3);
if(num3<100) work(x+1,hzx+member[x].c, num1, num2, num3+1);
return;
}
int main(){
		freopen("club.in","r",stdin);
	freopen("club","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>t;
while(t--){
	cin>>n;
int num[4];
memset(num,0,sizeof(num));
int m=n/2;//每个社团最大人数 
for(int i=1;i<=n;i++){
	int A,B,C;
	cin>>A>>B>>C;
	member[i].a=A;
	member[i].b=B;
	member[i].c=C;
int s1=max(A,B);
int s2=max(s1,C);
if(s2==A){
//	member[i].dangqianshuanze=1;
	member[i].max1=1;
	member[i].maxp[1]=1;
	s1=max(B,C);
	if(s1==B){
		member[i].max2=2;
		member[i].maxp[2]=2;
		member[i].cha1=A-B;
		member[i].max3=3;
		member[i].maxp[3]=3;
		member[i].cha2=B-C;
	}else{
		member[i].max2=3;
		member[i].maxp[2]=3;
		member[i].cha1=A-C;
		member[i].max3=2;
		member[i].maxp[3]=2;
		member[i].cha2=C-B;
	}
}else{
if(s2==B){
	//	member[i].dangqianshuanze=2;
	member[i].max1=2;
	member[i].maxp[1]=2;
	s1=max(A,C);
	if(s1==A){
		member[i].max2=1;
		member[i].maxp[2]=1;
		member[i].cha1=B-A;
		member[i].max3=3;
		member[i].maxp[3]=3;
		member[i].cha2=A-C;
	}else{member[i].max2=3;
	member[i].maxp[2]=3;
		member[i].cha1=B-C;
		member[i].max3=1;
		member[i].maxp[3]=1;
		member[i].cha2=C-A;
	}
	}else{
	//member[i].dangqianshuanze=3;
	member[i].max1=3;
	member[i].maxp[1]=3;
	s1=max(B,A);
	if(s1==A){
		member[i].max2=1;
		member[i].maxp[2]=1;
		member[i].cha1=C-A;
		member[i].max3=2;
		member[i].maxp[3]=2;
		member[i].cha2=A-B;
	}else{member[i].max2=2;
	member[i].maxp[2]=2;
		member[i].cha1=C-B;
		member[i].max3=1;
		member[i].maxp[3]=1;
		member[i].cha2=B-A;
	}
	}
}
//cout<<member[i].max1<<" "<<member[i].max2<<" "<<member[i].max3<<" "<<member[i].cha1<<" "<<member[i].cha2<<endl;
}
if(n>200){
	if(member[1].b==0&&member[1].c==0){
	sort(member,member+1+n,cmp);
for(int i=1;i<=m;i++){
	ans+=member[i].a;
}
	}
}else{
	for(int i=1;i<=n;i++){
		if(num[member[i].maxp[member[i].id]]<m){
			num[member[i].maxp[member[i].id]]++;
			ans+=member[i].maxp[member[i].id];
			member[i].id++;
		}else{
			for(int l=1;l<i;l++){
				if(member[l].maxp[member[l].id-1]==member[i].maxp[member[i].id]){
	
				}
			}
		}
	}
//work(1,0,0,0,0);
}

}cout<<ans;
	return 0;
}
