#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
long long num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]){
					num=(num+1)%998244353;
				}
			}
		}
	}
		for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
					if(a[i]+a[j]+a[k]>a[k1]){
					num=(num+1)% 998244353;
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
					if(a[i]+a[j]+a[k]+a[k1]>a[k2]){num=(num+1)% 998244353;}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]>a[k3]){num=(num+1)% 998244353;}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
				for(int k4=k3+1;k4<=n;k4++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]>a[k4]){num=(num+1)% 998244353;}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
				for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]>a[k5]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
				for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]>a[k6]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
				for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]>a[k7]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]>a[k8]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]>a[k9]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]>a[k10]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]>a[k11]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				for(int k12=k11+1;k12<=n;k12++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]>a[k12]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				for(int k12=k11+1;k12<=n;k12++){
				for(int k13=k12+1;k13<=n;k13++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]>a[k13]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				for(int k12=k11+1;k12<=n;k12++){
				for(int k13=k12+1;k13<=n;k13++){
				for(int k14=k13+1;k14<=n;k14++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]>a[k14]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				for(int k12=k11+1;k12<=n;k12++){
				for(int k13=k12+1;k13<=n;k13++){
				for(int k14=k13+1;k14<=n;k14++){
				for(int k15=k14+1;k15<=n;k15++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]>a[k15]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int k1=k+1;k1<=n;k1++){
				for(int k2=k1+1;k2<=n;k2++){
				for(int k3=k2+1;k3<=n;k3++){
			    for(int k4=k3+1;k4<=n;k4++){
				for(int k5=k4+1;k5<=n;k5++){
				for(int k6=k5+1;k6<=n;k6++){
				for(int k7=k6+1;k7<=n;k7++){
				for(int k8=k7+1;k8<=n;k8++){
				for(int k9=k8+1;k9<=n;k9++){
				for(int k10=k9+1;k10<=n;k10++){
				for(int k11=k10+1;k11<=n;k11++){
				for(int k12=k11+1;k12<=n;k12++){
				for(int k13=k12+1;k13<=n;k13++){
				for(int k14=k13+1;k14<=n;k14++){
				for(int k15=k14+1;k15<=n;k15++){
				for(int k16=k15+1;k16<=n;k16++){
				if(a[i]+a[j]+a[k]+a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]>a[k16]){num=(num+1)% 998244353;}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}
		}
	}
	cout<<num;
	return 0;
}
