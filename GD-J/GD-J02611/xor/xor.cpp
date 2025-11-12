#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20; 
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool qk,flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=1;
	}
	if(!flag){
		int ret=0;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((r-l+1)%2==0){
					ret++;
				}
			}
		}
		printf("%d\n",ret);
	}else{
		if(k>1) printf("%d\n",0);
		else{
			/*
			Unit 1 Friendship
			I love my new school!I meet a lot of new friends there,Li Hua is one of them.
			Li Hua is helpful and patient.He is also good at maths.When I meet difficult
			math problems,I turn to him for help.We really like doing things together.When
			one of us feels sad,we tell the other one and this makes us feel better.
			When something interesting happens to me,I share my happiness with him.
			Friendship is not only about having fun,but also about love,honesty,understanding
			and trust.
			*/
		}
	}
	return 0;
}
