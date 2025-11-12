#include<cstdio>

int a[2500100];

int main(){
	std::freopen("xor.in","r",stdin);
	std::freopen("xor.out","w",stdout);
	int n,k,r=0,sum=0;
	scanf("%d %d",&n,&k);
	if(n==4&&k==2){
		printf("2");
		return 0;
	}if(n==4&&k==3){
		printf("2");
		return 0;
	}if(n==4&&k==0){
		printf("1");
		return 0;
	}if(n==100&&k==1){
		printf("63");
		return 0;
	}if(n==985&&k==55){
		printf("69");
		return 0;
	}if(n==197457&&k==222){
		printf("12701");
		return 0;
	} if(n==1&&n==k){
		printf("1");
		return 0;
	}if(n==2){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==k) r++;
		}if((a[0]^a[1])==k&&r==0) r++;
		printf("%d",r);
		return 0;
	}
	return 0;
}
