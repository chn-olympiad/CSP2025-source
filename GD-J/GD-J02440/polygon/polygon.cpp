#include <bits/stdc++.h>
using namespace std;
int n,a[25],p=2,QK,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	sort(a+1,a+n+1);
	if(n==3){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}

	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n;k++){
				if(a[i]+a[j]+a[k] > a[k] * 2)
					QK++;
			}
		}
	}
	if(n==4){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;

	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n;m++){
					if(a[i]+a[j]+a[k]+a[m] > a[m]*2)
						QK++;
				}
			}
		}
	}
	if(n==5){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;

	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n;z++){
						if(a[i]+a[j]+a[k]+a[m]+a[z] > a[z]*2)
							QK++;
					}
				}
			}
		}
	}
	if(n==6){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;
	
	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n-p+m;z++){
						for(int x=z+1;x<=n;x++){
							if(a[i]+a[j]+a[k]+a[m]+a[z]+a[x] > a[x]*2)
								QK++;
						}
					}
				}
			}
		}
	}
	if(n==7){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;
	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n-p+m;z++){
						for(int x=z+1;x<=n-p+z;x++){
							for(int c = x+1;c<=n;c++){
								if(a[i]+a[j]+a[k]+a[m]+a[z]+a[x]+a[c] > a[c]*2)
									QK++;
							}
						}
					}
				}
			}
		}
	}
	if(n==8){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;
	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n-p+m;z++){
						for(int x=z+1;x<=n-p+z;x++){
							for(int c = x+1;c<=n-p+x;c++){
								for(int v =c+1;v<=n;v++){
									if(a[i]+a[j]+a[k]+a[m]+a[z]+a[x]+a[c]+a[v] > a[v]*2)
										QK++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==9){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;
	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n-p+m;z++){
						for(int x=z+1;x<=n-p+z;x++){
							for(int c = x+1;c<=n-p+x;c++){
								for(int v =c+1;v<=n-p+c;v++){
									for(int q = v+1;q<=n;q++){
										if(a[i]+a[j]+a[k]+a[m]+a[z]+a[x]+a[c]+a[v]+a[q] > a[q]*2)
											QK++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==10){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
	p++;
	
	for(int i = 1;i<=n-p;i++){
		for(int j = i+1;j<=n-p+i;j++){
			for(int k = j+1;k<=n-p+j;k++){
				for(int m = k+1;m<=n-p+k;m++){
					for(int z = m+1;z<=n-p+m;z++){
						for(int x=z+1;x<=n-p+z;x++){
							for(int c = x+1;c<=n-p+x;c++){
								for(int v =c+1;v<=n-p+c;v++){
									for(int q = v+1;q<=n-p+v;q++){
										for(int w = q+1;w<=n;w++){
											if(a[i]+a[j]+a[k]+a[m]+a[z]+a[x]+a[c]+a[v]+a[q]+a[w] > a[w]*2)
												QK++;
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
	if(n==11){
		for(int i = 1;i<=n;i++)
			sum+=a[i];
		if(sum>a[n]*2){
			QK++;		
			cout << QK;
			return 0;
		}
	}
}
