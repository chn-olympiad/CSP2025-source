#include<bits/stdc++.h>
using namespace std;

int t,n,midnum;
int personum[4];//第i个社团现在有多少人 
long long sum;
int a[100010][4],mx[100010],mid[100010],mi[100010];//mx存当前的人对哪个社团满意度最高 
int bnum[100010];//对几个社团满意度不为0 
bool one1,two2,three3;
int usd[100010];

void searc(int i){
	if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
		mx[i]=1;
		if(a[i][2]>a[i][3]){
			mid[i]=2;
			mi[i]=3;
		}else{
			mid[i]=3;
			mi[i]=2;
		}
		return;
	}
	if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
		mx[i]=2;
		if(a[i][1]>a[i][3]){
			mid[i]=1;
			mi[i]=3;
		}else{
			mid[i]=3;
			mi[i]=1;
		}
		return;
	}
	if(a[i][3]>a[i][2] && a[i][3]>a[i][1]){
		mx[i]=3;
		if(a[i][1]>a[i][2]){
			mid[i]=1;
			mi[i]=2;
		}else{
			mid[i]=2;
			mi[i]=1;
		}
		return;
	}
}
void special1(){
	for(int i=1;i<=n;i++) bnum[i]=a[i][1];
	sort(bnum+1,bnum+n+1);
	for(int i=n;i>midnum;i--) sum+=bnum[i];
}
void special2(){
	for(int i=1;i<=n;i++)
		bnum[i]=a[i][2];
	sort(bnum+1,bnum+n+1);
	for(int i=n;i>midnum;i--) sum+=bnum[i];
}
void special3(){
	for(int i=1;i<=n;i++) bnum[i]=a[i][3];
	sort(bnum+1,bnum+n+1);
	for(int i=n;i>midnum;i--) sum+=bnum[i];
}
int judge12(int i){
	if(usd[i]==1) return 2;
	else return 1;
}
void special12(){
	for(int i=1;i<=n;i++){
		if(personum[mx[i]]<midnum){
			sum+=a[i][mx[i]];
			personum[mx[i]]++;
			usd[i]=mx[i];
		}else{
			sum+=a[i][mid[i]];
			personum[mid[i]]++;
			usd[i]=mid[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && a[i][judge12(i)]-a[i][usd[i]]+a[j][judge12(j)]-a[j][usd[j]]>0){
				sum+=(a[i][judge12(i)]-a[i][usd[i]]+a[j][judge12(j)]-a[j][usd[j]]);
				usd[i]=judge12(i);
				usd[j]=judge12(j);
			}
		}
	}
}
int judge23(int i){
	if(usd[i]==3) return 2;
	else return 2;
}
void special23(){
	for(int i=1;i<=n;i++){
		if(personum[mx[i]]<midnum){
			sum+=a[i][mx[i]];
			personum[mx[i]]++;
			usd[i]=mx[i];
		}else{
			sum+=a[i][mid[i]];
			personum[mid[i]]++;
			usd[i]=mid[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && a[i][judge23(i)]-a[i][usd[i]]+a[j][judge23(j)]-a[j][usd[j]]>0){
				sum+=(a[i][judge23(i)]-a[i][usd[i]]+a[j][judge23(j)]-a[j][usd[j]]);
				usd[i]=judge23(i);
				usd[j]=judge23(j);
			}
		}
	}
}
int judge13(int i){
	if(usd[i]==3) return 1;
	else return 3;
}
void special13(){
	for(int i=1;i<=n;i++){
		if(personum[mx[i]]<midnum){
			sum+=a[i][mx[i]];
			personum[mx[i]]++;
			usd[i]=mx[i];
		}else{
			sum+=a[i][mid[i]];
			personum[mid[i]]++;
			usd[i]=mid[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && a[i][judge13(i)]-a[i][usd[i]]+a[j][judge13(j)]-a[j][usd[j]]>0){
				sum+=(a[i][judge13(i)]-a[i][usd[i]]+a[j][judge13(j)]-a[j][usd[j]]);
				usd[i]=judge13(i);
				usd[j]=judge13(j);
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		personum[1]=0;personum[2]=0;personum[3]=0;
		midnum=n/2;
		one1=1;two2=1;three3=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			usd[i]=0;
			bnum[i]=0;
			searc(i);
			if(a[i][1]!=0){
				one1=0;
				bnum[i]++;
			}
			if(a[i][2]!=0){
				two2=0;
				bnum[i]++;
			}
			if(a[i][3]!=0){
				three3=0;
				bnum[i]++;
			}
		}
		if(two2 && three3) special1();
		else if(one1 && three3) special2();
		else if(two2 && one1) special3();
		else if(three3) special12();
		else if(one1) special23();
		else if(two2) special13();
		else{
			for(int i=1;i<=n;i++){
				if(personum[mx[i]]<midnum){
					sum+=a[i][mx[i]];
					personum[mx[i]]++;
					usd[i]=mx[i];
				}else if(personum[mid[i]]<midnum){
					sum+=a[i][mid[i]];
					personum[mid[i]]++;
					usd[i]=mid[i];
				}else{
					sum+=a[i][mi[i]];
					personum[mi[i]]++;
					usd[i]=mi[i];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						if(usd[i]==1){
							int tmp;
							if(a[i][2]>a[i][3]) tmp=2;
							else tmp=3;
							if(personum[tmp]<midnum && a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]>0){
								sum+=(a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]);
								usd[i]=tmp;
								usd[j]=tmp;
							}
						}
						if(usd[i]==2){
							int tmp;
							if(a[i][1]>a[i][3]) tmp=1;
							else tmp=3;
							if(personum[tmp]<midnum && a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]>0){
								sum+=(a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]);
								usd[i]=tmp;
								usd[j]=tmp;
							}
						}
						if(usd[i]==3){
							int tmp;
							if(a[i][2]>a[i][1]) tmp=2;
							else tmp=1;
							if(personum[tmp]<midnum && a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]>0){
								sum+=(a[i][tmp]-a[i][usd[i]]+a[j][tmp]-a[j][usd[j]]);
								usd[i]=tmp;
								usd[j]=tmp;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
