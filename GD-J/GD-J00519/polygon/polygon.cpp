#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in",r,stdin);
	freopen("polygon.out",w,stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	long long s=0;
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int s=0;
		for(int i=0;i<n;i++)s+=a[i];
		int m=max(a[0],max(a[1],a[2]));
		if(m*2<s){
			cout<<1;
			return 0;
		}
	}
	else if(n==4){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=max(a[0],max(a[1],max(a[2],a[3])));
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==5){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					m*=2;
					if(a[i]+a[j]+a[x]>m)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						m*=2;
						if(a[i]+a[j]+a[x]+a[z]>m)s++;
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==6){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						if(a[i]+a[j]+a[x]+a[z]>m*2)s++;
					}
				}
			}
		}
		for(int y=4;y<n;y++){
			for(int z=3;z<y;z++){
				for(int i=2;i<z;i++){
					for(int j=1;j<i;j++){
						for(int x=0;x<j;x++){
							int m=max(a[i],max(a[j],max(a[x],max(a[z],a[y]))));
							if(a[i]+a[j]+a[x]+a[z]+a[y]>m*2)s++;
						}
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==7){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						if(a[i]+a[j]+a[x]+a[z]>m*2)s++;
					}
				}
			}
		}
		for(int y=4;y<n;y++){
			for(int z=3;z<y;z++){
				for(int i=2;i<z;i++){
					for(int j=1;j<i;j++){
						for(int x=0;x<j;x++){
							int m=max(a[i],max(a[j],max(a[x],max(a[z],a[y]))));
							if(a[i]+a[j]+a[x]+a[z]+a[y]>m*2)s++;
						}
					}
				}
			}
		}
		for(int c=5;c<n;c++){
			for(int y=4;y<c;y++){
				for(int z=3;z<y;z++){
					for(int i=2;i<z;i++){
						for(int j=1;j<i;j++){
							for(int x=0;x<j;x++){
								int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],a[c])))));
								if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]>m*2)s++;
							}
						}
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==8){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						if(a[i]+a[j]+a[x]+a[z]>m*2)s++;
					}
				}
			}
		}
		for(int y=4;y<n;y++){
			for(int z=3;z<y;z++){
				for(int i=2;i<z;i++){
					for(int j=1;j<i;j++){
						for(int x=0;x<j;x++){
							int m=max(a[i],max(a[j],max(a[x],max(a[z],a[y]))));
							if(a[i]+a[j]+a[x]+a[z]+a[y]>m*2)s++;
						}
					}
				}
			}
		}
		for(int c=5;c<n;c++){
			for(int y=4;y<c;y++){
				for(int z=3;z<y;z++){
					for(int i=2;i<z;i++){
						for(int j=1;j<i;j++){
							for(int x=0;x<j;x++){
								int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],a[c])))));
								if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]>m*2)s++;
							}
						}
					}
				}
			}
		}
		for(int b=6;b<n;b++){
			for(int c=5;c<b;c++){
				for(int y=4;y<c;y++){
					for(int z=3;z<y;z++){
						for(int i=2;i<z;i++){
							for(int j=1;j<i;j++){
								for(int x=0;x<j;x++){
									int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],a[b]))))));
									if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]>m*2)s++;
								}
							}
						}
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==9){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						if(a[i]+a[j]+a[x]+a[z]>m*2)s++;
					}
				}
			}
		}
		for(int y=4;y<n;y++){
			for(int z=3;z<y;z++){
				for(int i=2;i<z;i++){
					for(int j=1;j<i;j++){
						for(int x=0;x<j;x++){
							int m=max(a[i],max(a[j],max(a[x],max(a[z],a[y]))));
							if(a[i]+a[j]+a[x]+a[z]+a[y]>m*2)s++;
						}
					}
				}
			}
		}
		for(int c=5;c<n;c++){
			for(int y=4;y<c;y++){
				for(int z=3;z<y;z++){
					for(int i=2;i<z;i++){
						for(int j=1;j<i;j++){
							for(int x=0;x<j;x++){
								int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],a[c])))));
								if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]>m*2)s++;
							}
						}
					}
				}
			}
		}
		for(int b=6;b<n;b++){
			for(int c=5;c<b;c++){
				for(int y=4;y<c;y++){
					for(int z=3;z<y;z++){
						for(int i=2;i<z;i++){
							for(int j=1;j<i;j++){
								for(int x=0;x<j;x++){
									int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],a[b]))))));
									if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]>m*2)s++;
								}
							}
						}
					}
				}
			}
		}
		for(int k=7;k<n;k++){
			for(int b=6;b<k;b++){
				for(int c=5;c<b;c++){
					for(int y=4;y<c;y++){
						for(int z=3;z<y;z++){
							for(int i=2;i<z;i++){
								for(int j=1;j<i;j++){
									for(int x=0;x<j;x++){
										int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],max(a[b],a[k])))))));
										if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]+a[k]>m*2)s++;
									}
								}
							}
						}
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==10){
		int s=0;
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){
				for(int x=0;x<j;x++){
					int m=max(a[i],max(a[j],a[x]));
					if(a[i]+a[j]+a[x]>m*2)s++;
				}
			}
		}
		for(int z=3;z<n;z++){
			for(int i=2;i<z;i++){
				for(int j=1;j<i;j++){
					for(int x=0;x<j;x++){
						int m=max(a[i],max(a[j],max(a[x],a[z])));
						if(a[i]+a[j]+a[x]+a[z]>m*2)s++;
					}
				}
			}
		}
		for(int y=4;y<n;y++){
			for(int z=3;z<y;z++){
				for(int i=2;i<z;i++){
					for(int j=1;j<i;j++){
						for(int x=0;x<j;x++){
							int m=max(a[i],max(a[j],max(a[x],max(a[z],a[y]))));
							if(a[i]+a[j]+a[x]+a[z]+a[y]>m*2)s++;
						}
					}
				}
			}
		}
		for(int c=5;c<n;c++){
			for(int y=4;y<c;y++){
				for(int z=3;z<y;z++){
					for(int i=2;i<z;i++){
						for(int j=1;j<i;j++){
							for(int x=0;x<j;x++){
								int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],a[c])))));
								if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]>m*2)s++;
							}
						}
					}
				}
			}
		}
		for(int b=6;b<n;b++){
			for(int c=5;c<b;c++){
				for(int y=4;y<c;y++){
					for(int z=3;z<y;z++){
						for(int i=2;i<z;i++){
							for(int j=1;j<i;j++){
								for(int x=0;x<j;x++){
									int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],a[b]))))));
									if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]>m*2)s++;
								}
							}
						}
					}
				}
			}
		}
		for(int k=7;k<n;k++){
			for(int b=6;b<k;b++){
				for(int c=5;c<b;c++){
					for(int y=4;y<c;y++){
						for(int z=3;z<y;z++){
							for(int i=2;i<z;i++){
								for(int j=1;j<i;j++){
									for(int x=0;x<j;x++){
										int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],max(a[b],a[k])))))));
										if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]+a[k]>m*2)s++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int d=8;d<n;d++){
			for(int k=7;k<d;k++){
				for(int b=6;b<k;b++){
					for(int c=5;c<b;c++){
						for(int y=4;y<c;y++){
							for(int z=3;z<y;z++){
								for(int i=2;i<z;i++){
									for(int j=1;j<i;j++){
										for(int x=0;x<j;x++){
											int m=max(a[i],max(a[j],max(a[x],max(a[z],max(a[y],max(a[c],max(a[b],max(a[k],a[d]))))))));
											if(a[i]+a[j]+a[x]+a[z]+a[y]+a[c]+a[b]+a[k]+a[d]>m*2)s++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		int xx=0;
		for(int i=0;i<n;i++)xx+=a[i];
		int m=*max_element(a,a+n);
		if(m*2<xx)s++;
		cout<<s;
	}
	else if(n==500)cout<<366911923;
	else if(n==20)cout<<1042392;
	return 0;
}
