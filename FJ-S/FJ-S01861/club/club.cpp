#include<bits/stdc++.h>
using namespace std;
struct p{
	long long x1,x2,x3;
}a[100005];
int T,n;
int s[15];
long long ss[15];
bool cmp1(p x,p y){
	if(x.x1!=y.x1){
		return x.x1>y.x1;
	}else{
		if(x.x2!=y.x2){
			return x.x2>y.x2;
		}
	}
	return x.x3>y.x3;

}
	
bool cmp2(p x,p y){
	if(x.x2!=y.x2){
		return x.x2>y.x2;
	}else{
		if(x.x1!=y.x1){
			return x.x1>y.x1;
		}
	}
	return x.x3>y.x3;
}
bool cmp3(p x,p y){
	if(x.x3!=y.x3){
		return x.x3>y.x3;
	}else{
		if(x.x1!=y.x1){
			return x.x1>y.x1;
		}
	}
	return x.x2>y.x2;
}
bool cmp4(p x,p y){
	if(x.x1!=y.x1){
		return x.x1>y.x1;
	}else{
		if(x.x3!=y.x3){
			return x.x3>y.x3;
		}
	}
	return x.x2>y.x2;
}
bool cmp5(p x,p y){
	if(x.x2!=y.x2){
		return x.x2>y.x2;
	}else{
		if(x.x3!=y.x3){
			return x.x3>y.x3;
		}
	}
	return x.x1>y.x1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=10;i++){
			ss[i]=0;
			s[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		sort(a+1,a+1+n,cmp1);
		if(n>=200&&a[1].x2==0&&a[1].x3==0){
			long long sss=0;
			for(int i=1;i<=n/2;i++){
				sss+=a[i].x1;
			}
			cout<<sss<<"\n";
			continue;
		}
		ss[1]=a[1].x1;
		s[1]++;
		for(int i=2;i<=n;i++){
			int h=max(a[i].x1,max(a[i].x2,a[i].x3));
			if(h==a[i].x1){
				if(s[1]<n/2){
					s[1]++;
					ss[1]+=h;
				}else{
					int k=max(a[i].x2,a[i].x3);
					if(k==a[i].x2){
						if(s[2]<n/2){
							s[2]++;
							ss[1]+=k;
						}else{
							s[3]++;
							ss[1]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[1]+=k;
						}else{
							s[2]++;
							ss[1]+=a[i].x2;
						}
					}
				}
			}else if(h==a[i].x2){
					if(s[2]<n/2){
						s[2]++;
						ss[1]+=h;
					}else{
						int k=max(a[i].x1,a[i].x3);
						if(k==a[i].x1){
							if(s[1]<n/2){
							s[1]++;
							ss[1]+=k;
						}else{
							s[3]++;
							ss[1]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[1]+=k;
						}else{
							s[1]++;
							ss[1]+=a[i].x1;
						}
					}
				}
			}else{
				if(s[3]<n/2){
					s[3]++;
					ss[1]+=h;
				}else{
					int k=max(a[i].x1,a[i].x2);
					if(k==a[i].x1){
						if(s[1]<n/2){
							s[1]++;
							ss[1]+=k;
						}else{
							s[2]++;
							ss[1]+=a[i].x2;
						}
					}else{
						if(s[2]<n/2){
							s[2]++;
							ss[1]+=k;
						}else{
							s[1]++;
							ss[1]+=a[i].x1;
						}
					}
				}
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=10;i++){
			s[i]=0;
		}
		ss[2]=a[1].x2;
		s[2]++;
		for(int i=2;i<=n;i++){
			int h=max(a[i].x1,max(a[i].x2,a[i].x3));
			if(h==a[i].x2){
				if(s[2]<n/2){
					s[2]++;
					ss[2]+=h;
				}else{
					int k=max(a[i].x1,a[i].x3);
					if(k==a[i].x1){
						if(s[1]<n/2){
							s[1]++;
							ss[2]+=k;
						}else{
							s[3]++;
							ss[2]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[2]+=k;
						}else{
							s[1]++;
							ss[2]+=a[i].x1;
						}
					}
				}
			}else if(h==a[i].x1){
				if(s[1]<n/2){
					s[1]++;
					ss[2]+=h;
				}else{
					int k=max(a[i].x2,a[i].x3);
					if(k==a[i].x2){
						if(s[2]<n/2){
							s[2]++;
							ss[2]+=k;
						}else{
							s[3]++;
							ss[2]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[2]+=k;
						}else{
							s[2]++;
							ss[2]+=a[i].x2;
						}	
					}
				}
			}else{
				if(s[3]<n/2){
					s[3]++;
					ss[2]+=h;
				}else{
					int k=max(a[i].x1,a[i].x2);
					if(k==a[i].x2){
						if(s[2]<n/2){
							s[2]++;
							ss[2]+=k;
						}else{
							s[1]++;
							ss[2]+=a[i].x1;
						}
					}else{
						if(s[1]<n/2){
							s[1]++;
							ss[2]+=k;
						}else{
							s[2]++;
							ss[2]+=a[i].x2;
						}
					}
				}
			}
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=10;i++){
			s[i]=0;
		}
		ss[3]=a[1].x3;
		s[3]++;
		for(int i=2;i<=n;i++){
			int h=max(a[i].x1,max(a[i].x2,a[i].x3));
			if(h==a[i].x3){
				if(s[3]<n/2){
					s[3]++;
					ss[3]+=h;
				}else{
					int k=max(a[i].x1,a[i].x2);
					if(k==a[i].x1){
						if(s[1]<n/2){
							s[1]++;
							ss[3]+=k;
						}else{
							s[3]++;
							ss[3]+=a[i].x2;
						}
					}else{
						if(s[2]<n/2){
							s[2]++;
							ss[3]+=k;
						}else{
							s[1]++;
							ss[3]+=a[i].x1;
						}
					}
				}
			}else if(h==a[i].x1){
				if(s[1]<n/2){
					s[1]++;
					ss[3]+=h;
				}else{
					int k=max(a[i].x2,a[i].x3);
					if(k==a[i].x3){
						if(s[3]<n/2){
							s[3]++;
							ss[3]+=k;
						}else{
							s[3]++;
							ss[3]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[3]+=k;
						}else{
							s[2]++;
							ss[3]+=a[i].x2;
						}	
					}
				}
			}else{
				if(s[2]<n/2){
					s[2]++;
					ss[3]+=h;
				}else{
					int k=max(a[i].x1,a[i].x3);
					if(k==a[i].x3){
						if(s[3]<n/2){
							s[3]++;
							ss[3]+=k;
						}else{
							s[1]++;
							ss[3]+=a[i].x1;
						}
					}else{
						if(s[1]<n/2){
							s[1]++;
							ss[3]+=k;
						}else{
							s[3]++;
							ss[3]+=a[i].x3;
						}
					}
				}
			}
		}
		sort(a+1,a+1+n,cmp5);
		for(int i=1;i<=10;i++){
			s[i]=0;
		}
		ss[4]=a[1].x1;
		s[1]++;
		for(int i=2;i<=n;i++){
			int h=max(a[i].x1,max(a[i].x2,a[i].x3));
			if(h==a[i].x1){
				if(s[1]<n/2){
					s[1]++;
					ss[4]+=h;
				}else{
					int k=max(a[i].x2,a[i].x3);
					if(k==a[i].x3){
						if(s[3]<n/2){
							s[3]++;
							ss[4]+=k;
						}else{
							s[2]++;
							ss[4]+=a[i].x2;
						}
					}else{
						if(s[2]<n/2){
							s[2]++;
							ss[4]+=k;
						}else{
							s[3]++;
							ss[4]+=a[i].x3;
						}
					}
				}
			}else if(h==a[i].x3){
					if(s[3]<n/2){
						s[3]++;
						ss[4]+=h;
					}else{
						int k=max(a[i].x1,a[i].x2);
						if(k==a[i].x1){
							if(s[1]<n/2){
							s[1]++;
							ss[4]+=k;
						}else{
							s[2]++;
							ss[4]+=a[i].x2;
						}
					}else{
						if(s[2]<n/2){
							s[2]++;
							ss[4]+=k;
						}else{
							s[1]++;
							ss[4]+=a[i].x1;
						}
					}
				}
			}else{
				if(s[2]<n/2){
					s[2]++;
					ss[4]+=h;
				}else{
					int k=max(a[i].x1,a[i].x3);
					if(k==a[i].x1){
						if(s[1]<n/2){
							s[1]++;
							ss[4]+=k;
						}else{
							s[3]++;
							ss[4]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[4]+=k;
						}else{
							s[3]++;
							ss[4]+=a[i].x3;
						}
					}
				}
			}
		}
		sort(a+1,a+1+n,cmp5);
		for(int i=1;i<=10;i++){
			s[i]=0;
		}
		ss[5]=a[1].x2;
		s[2]++;
		for(int i=2;i<=n;i++){
			int h=max(a[i].x1,max(a[i].x2,a[i].x3));
			if(h==a[i].x2){
				if(s[2]<n/2){
					s[2]++;
					ss[5]+=h;
				}else{
					int k=max(a[i].x1,a[i].x3);
					if(k==a[i].x3){
						if(s[3]<n/2){
							s[3]++;
							ss[5]+=k;
						}else{
							s[1]++;
							ss[5]+=a[i].x1;
						}
					}else{
						if(s[1]<n/2){
							s[1]++;
							ss[5]+=k;
						}else{
							s[3]++;
							ss[5]+=a[i].x3;
						}
					}
				}
			}else if(h==a[i].x3){
				if(s[3]<n/2){
					s[3]++;
					ss[5]+=h;
				}else{
					int k=max(a[i].x2,a[i].x1);
					if(k==a[i].x2){
						if(s[2]<n/2){
							s[2]++;
							ss[5]+=k;
						}else{
							s[1]++;
							ss[5]+=a[i].x1;
						}
					}else{
						if(s[1]<n/2){
							s[1]++;
							ss[5]+=k;
						}else{
							s[2]++;
							ss[5]+=a[i].x2;
						}	
					}
				}
			}else{
				if(s[1]<n/2){
					s[1]++;
					ss[5]+=h;
				}else{
					int k=max(a[i].x3,a[i].x2);
					if(k==a[i].x2){
						if(s[2]<n/2){
							s[2]++;
							ss[5]+=k;
						}else{
							s[3]++;
							ss[5]+=a[i].x3;
						}
					}else{
						if(s[3]<n/2){
							s[3]++;
							ss[5]+=k;
						}else{
							s[2]++;
							ss[5]+=a[i].x2;
						}
					}
				}
			}
		}
		cout<<max(ss[5],max(ss[4],max(ss[1],max(ss[2],ss[3]))))<<"\n";
	}

	return 0;
} 
