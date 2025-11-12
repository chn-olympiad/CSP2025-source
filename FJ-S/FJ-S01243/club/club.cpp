#include<bits/stdc++.h>
using namespace std;


void process_etc(int);
void process1e5(int);
void process2();

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==2){
			process2();
		}
		else if(n==int(pow(10,5))){
			process1e5(n);
		}
		else process_etc(n);
	}
	
	return 0;
}

void read(int *o){
	for(int i=0;i<3;i++){
		scanf("%d",&o[i]);
	}
}

void process2(){
	int sum=0;
	int o1[3],o2[3];
	read(o1);
	read(o2);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j)continue;
			sum=max(sum,o1[i]+o2[j]);
		}
	}
	printf("%d\n",sum);
}


void process_etc(int n){
	int sum=0;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		sum+=max(max(a,b),c);
	}
	printf("%d\n",sum);
}


void process1e5(int n){
	int sum=0;
	int *a1=new int[n];
	for(int i=0;i<n;i++)scanf("%d",&a1[i]);
	sort(a1,a1+n);
	for(int i=0;i<n/2;i++){
		sum+=a1[i];
	}
	printf("%d\n",sum);
}

	

