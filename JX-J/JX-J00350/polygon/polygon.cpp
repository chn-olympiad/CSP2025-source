#include <bits/stdc++.h>
using namespace std;

int n,a[5005],ant=0;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n==3){
		if(a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[2]+a[0]>a[1]){
			cout<<1;
			return 0;
		}
	}else if(n==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
					}
				}
			}
		}
	}else if(n==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
						}
					}
				}
			}
		}
	}else if(n==6){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
							for(int i6=i5+1;i6<n;i6++){
							int x6 = max(a[i6],x5);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]>2*x6)ant++;
						}
						}
					}
				}
			}
		}
	}else if(n==7){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
							for(int i6=i5+1;i6<n;i6++){
							int x6 = max(a[i6],x5);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]>2*x6)ant++;
							for(int i7=i6+1;i7<n;i7++){
							int x7 = max(a[i7],x6);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]>2*x7)ant++;
						}
						}
						}
					}
				}
			}
		}
	}else if(n==8){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
							for(int i6=i5+1;i6<n;i6++){
							int x6 = max(a[i6],x5);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]>2*x6)ant++;
							for(int i7=i6+1;i7<n;i7++){
							int x7 = max(a[i7],x6);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]>2*x7)ant++;
							for(int i8=i7+1;i8<n;i8++){
							int x8 = max(a[i8],x7);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>2*x8)ant++;
						}
						}
						}
						}
					}
				}
			}
		}
	}else if(n==9){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
							for(int i6=i5+1;i6<n;i6++){
							int x6 = max(a[i6],x5);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]>2*x6)ant++;
							for(int i7=i6+1;i7<n;i7++){
							int x7 = max(a[i7],x6);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]>2*x7)ant++;
							for(int i8=i7+1;i8<n;i8++){
							int x8 = max(a[i8],x7);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>2*x8)ant++;
							for(int i9=i8+1;i9<n;i9++){
							int x9 = max(a[i9],x8);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>2*x9)ant++;
						}
						}
						}
						}
						}
					}
				}
			}
		}
	}else{
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int m = max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*m)ant++;
					for(int i4=k+1;i4<n;i4++){
						int x4 = max(a[i4],m);
						if(a[i]+a[j]+a[k]+a[i4]>2*x4)ant++;
						for(int i5=i4+1;i5<n;i5++){
							int x5 = max(a[i5],x4);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]>2*x5)ant++;
							for(int i6=i5+1;i6<n;i6++){
							int x6 = max(a[i6],x5);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]>2*x6)ant++;
							for(int i7=i6+1;i7<n;i7++){
							int x7 = max(a[i7],x6);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]>2*x7)ant++;
							for(int i8=i7+1;i8<n;i8++){
							int x8 = max(a[i8],x7);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>2*x8)ant++;
							for(int i9=i8+1;i9<n;i9++){
							int x9 = max(a[i9],x8);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>2*x9)ant++;
							for(int i10=i9+1;i10<n;i10++){
							int x10 = max(a[i10],x9);
							if(a[i]+a[j]+a[k]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>2*x10)ant++;
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
	cout<<ant;
	return 0;
}
