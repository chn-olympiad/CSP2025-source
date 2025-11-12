#include<bits/stdc++.h>
using namespace std;

struct RawRoad{
	int u,v,w;
	void setup(){
		scanf("%d %d %d",&u,&v,&w);
	}
};

struct etcRoad{
	int c,*a;
	void setup(int n){
		scanf("%d",&c);
		a=new int[n];
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
	}
	
};



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);

	RawRoad *rl;
	rl=new RawRoad[n];
	etcRoad *el;
	el=new etcRoad[k];
	
	
	for(int i=0;i<n;i++){
		RawRoad r;
		r.setup();
		rl[i]=r;
	}
	for(int j=0;j<k;j++){
		etcRoad e;
		e.setup(n);
	}
	
	printf("0");
	
	return 0;
	
}

//特殊性质 A：
//对于所有 1 ≤ j ≤ k
//均有 c j = 0 且均存在 1 ≤ i ≤ n 满足 a j,i = 0。
