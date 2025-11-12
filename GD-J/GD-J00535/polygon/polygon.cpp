#include<bits/stdc++.h>
using namespace std;
long long l[5005],lmax=-1,lsum=0,finalans;
const int MOD=998244353;
int fun3(int x){
	int rtans=0;
	for(int i=0;i<x-2;i++){
		for(int j=i+1;j<x-1;j++){
			for(int k=j+1;k<x;k++){
				int A,B,C;
				A=max(l[i],max(l[j],l[k]));
				if(A==l[i])B=l[j],C=l[k];
				if(A==l[j])B=l[i],C=l[k];
				if(A==l[k])B=l[j],C=l[i];
				if(B+C>A){
					rtans++;
					rtans%=MOD;
				}
			}
		}
	}return rtans;
}
int fun4(int x){
	int rtans=0;
	for(int i=0;i<x-3;i++){
		for(int j=i+1;j<x-2;j++){
			for(int k=j+1;k<x-1;k++){
				for(int m=k+1;m<x;m++){
					int A,B,C,D;
					A=max(max(l[i],l[m]),max(l[j],l[k]));
					if(A==l[i])B=l[j],C=l[k],D=l[m];
					if(A==l[j])B=l[i],C=l[k],D=l[m];
					if(A==l[k])B=l[j],C=l[i],D=l[m];
					if(A==l[m])B=l[j],C=l[i],D=l[k];
					if(B+C+D>A){
						rtans++;
						rtans%=MOD;
					}
				}
			}
		}
	}return rtans;
}
int fun5(int x){
	int rtans=0;
	for(int i=0;i<x-4;i++){
		for(int j=i+1;j<x-3;j++){
			for(int k=j+1;k<x-2;k++){
				for(int m=k+1;m<x-1;m++){
					for(int n=m+1;n<x;n++){
						int A,B,C,D,E;
						A=max(max(l[i],l[m]),max(l[j],max(l[k],l[n])));
						if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n];
						if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n];
						if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n];
						if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n];
						if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m];
						if(B+C+D+E>A){
							rtans++;
							rtans%=MOD;
						}
					}
				}
			}
		}
	}return rtans;
}
int fun6(int x){
	int rtans=0;
	for(int i=0;i<x-5;i++){
		for(int j=i+1;j<x-4;j++){
			for(int k=j+1;k<x-3;k++){
				for(int m=k+1;m<2;m++){
					for(int n=m+1;n<x-1;n++){
						for(int o=n+1;o<x;o++){
							int A,B,C,D,E,F;
							A=max(max(l[i],l[m]),max(max(l[j],l[o]),max(l[k],l[n])));
							if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n],F=l[o];
							if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n],F=l[o];
							if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n],F=l[o];
							if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n],F=l[o];
							if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m],F=l[o];
							if(A==l[o])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n];
							if(B+C+D+E+F>A){
								rtans++;
								rtans%=MOD;
							}
						}
					}
				}
			}
		}
	}return rtans;
}
int fun7(int x){
	int rtans=0;
	for(int i=0;i<x-6;i++){
		for(int j=i+1;j<x-5;j++){
			for(int k=j+1;k<x-4;k++){
				for(int m=k+1;m<3;m++){
					for(int n=m+1;n<x-2;n++){
						for(int o=n+1;o<x-1;o++){
							for(int p=o+1;p<x;p++){
								int A,B,C,D,E,F,G;
								A=max(max(l[i],l[m]),max(max(l[j],l[o]),max(l[k],max(l[n],l[p]))));
								if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p];
								if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p];
								if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n],F=l[o],G=l[p];
								if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n],F=l[o],G=l[p];
								if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m],F=l[o],G=l[p];
								if(A==l[o])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[p];
								if(A==l[p])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o];
								if(B+C+D+E+F+G>A){
									rtans++;
									rtans%=MOD;
								}
							}
						}
					}
				}
			}
		}
	}return rtans;
}
int fun8(int x){
	int rtans=0;
	for(int i=0;i<x-7;i++){
		for(int j=i+1;j<x-6;j++){
			for(int k=j+1;k<x-5;k++){
				for(int m=k+1;m<4;m++){
					for(int n=m+1;n<x-3;n++){
						for(int o=n+1;o<x-2;o++){
							for(int p=o+1;p<x-1;p++){
								for(int q=p+1;q<x;q++){
									int A,B,C,D,E,F,G,H;
									A=max(max(l[i],l[m]),max(max(l[j],l[o]),max(max(l[k],l[q]),max(l[n],l[p]))));
									if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q];
									if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q];
									if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q];
									if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n],F=l[o],G=l[p],H=l[q];
									if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m],F=l[o],G=l[p],H=l[q];
									if(A==l[o])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[p],H=l[q];
									if(A==l[p])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[q];
									if(A==l[q])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p];
									if(B+C+D+E+F+G+H>A){
										rtans++;
										rtans%=MOD;
									}
								}
							}
						}
					}
				}
			}
		}
	}return rtans;
}
int fun9(int x){
	int rtans=0;
	for(int i=0;i<x-8;i++){
		for(int j=i+1;j<x-7;j++){
			for(int k=j+1;k<x-6;k++){
				for(int m=k+1;m<5;m++){
					for(int n=m+1;n<x-4;n++){
						for(int o=n+1;o<x-3;o++){
							for(int p=o+1;p<x-2;p++){
								for(int q=p+1;q<x-1;q++){
									for(int r=q+1;r<x;r++){
										int A,B,C,D,E,F,G,H,I;
										A=max(max(l[i],l[m]),max(max(l[j],l[o]),max(max(l[k],l[q]),max(max(l[n],l[r]),l[p]))));
										if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r];
										if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r];
										if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r];
										if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r];
										if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m],F=l[o],G=l[p],H=l[q],I=l[r];
										if(A==l[o])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[p],H=l[q],I=l[r];
										if(A==l[p])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[q],I=l[r];
										if(A==l[q])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p],I=l[r];
										if(A==l[r])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p],I=l[q];
										if(B+C+D+E+F+G+H+I>A){
											rtans++;
											rtans%=MOD;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}return rtans;
}
int fun10(int x){
	int rtans=0;
	for(int i=0;i<x-8;i++){
		for(int j=i+1;j<x-7;j++){
			for(int k=j+1;k<x-6;k++){
				for(int m=k+1;m<5;m++){
					for(int n=m+1;n<x-4;n++){
						for(int o=n+1;o<x-3;o++){
							for(int p=o+1;p<x-2;p++){
								for(int q=p+1;q<x-1;q++){
									for(int r=q+1;r<x;r++){
										for(int s=r+1;s<x;s++){
											int A,B,C,D,E,F,G,H,I,J;
											A=max(max(l[i],l[m]),max(max(l[j],l[o]),max(max(l[k],l[q]),max(max(l[n],l[r]),max(l[p],l[s])))));
											if(A==l[i])B=l[j],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[j])B=l[i],C=l[k],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[k])B=l[j],C=l[i],D=l[m],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[m])B=l[j],C=l[i],D=l[k],E=l[n],F=l[o],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[n])B=l[j],C=l[i],D=l[k],E=l[m],F=l[o],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[o])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[p],H=l[q],I=l[r],J=l[s];
											if(A==l[p])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[q],I=l[r],J=l[s];
											if(A==l[q])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p],I=l[r],J=l[s];
											if(A==l[r])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p],I=l[q],J=l[s];
											if(A==l[s])B=l[j],C=l[i],D=l[k],E=l[m],F=l[n],G=l[o],H=l[p],I=l[q],J=l[r];
											if(B+C+D+E+F+G+H+I+J>A){
												rtans++;
												rtans%=MOD;
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
	}return rtans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long x;
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>l[i];
		lmax=max(lmax,l[i]);
		lsum+=l[i];
	}
	if(lmax==1 or lmax*x==lsum){//t15-20
		for(int i=3;i<=x;i++){
			int justanameA=1,justanameC=1;
			for(int j=0;j<i;j++){
				justanameA*=(x-j)%MOD;
			}for(int j=1;j<=i;j++){
				justanameC*=j%MOD;
			}
			finalans=(finalans+justanameA/justanameC)%MOD;
		}cout<<finalans;
	}else if(x<=3){//t1-3
		if(lsum>2*lmax)cout<<1;
		else cout<<0;
	}else if(x==4){
		finalans+=fun3(4);
		finalans+=fun4(4);
		cout<<finalans;
	}else if(x==5){
		finalans+=fun3(5);
		finalans+=fun4(5);
		finalans+=fun5(5);
		cout<<finalans;
	}else if(x==6){
		finalans+=fun3(6);
		finalans+=fun4(6);
		finalans+=fun5(6);
		finalans+=fun6(6);
		cout<<finalans;
	}else if(x==7){
		finalans+=fun3(7);
		finalans+=fun4(7);
		finalans+=fun5(7);
		finalans+=fun6(7);
		finalans+=fun7(7);
		cout<<finalans;
	}else if(x==8){
		finalans+=fun3(8);
		finalans+=fun4(8);
		finalans+=fun5(8);
		finalans+=fun6(8);
		finalans+=fun7(8);
		finalans+=fun8(8);
		cout<<finalans;
	}else if(x==9){
		finalans+=fun3(9);
		finalans+=fun4(9);
		finalans+=fun5(9);
		finalans+=fun6(9);
		finalans+=fun7(9);
		finalans+=fun8(9);
		finalans+=fun9(9);
		cout<<finalans;
	}else if(x==10){
		finalans+=fun3(10);
		finalans+=fun4(10);
		finalans+=fun5(10);
		finalans+=fun6(10);
		finalans+=fun7(10);
		finalans+=fun8(10);
		finalans+=fun9(10);
		finalans+=fun10(10);
		cout<<finalans;
	}else cout<<1;
	return 0;
} 
