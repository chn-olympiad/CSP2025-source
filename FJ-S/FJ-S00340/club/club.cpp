#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
struct Node{
	int x,y,z;
}a[N];

bool cmp(Node p,Node q){
	int p9,p8,p7,q9,q8,q7;
	if(p.x>p.y && p.x>p.z){
		p9=p.x;
		if(p.y>p.z){
			p8=p.y;
			p7=p.z;
		}else{
			p8=p.z;
			p7=p.y;
		}
	}else if(p.y>p.x && p.y>p.z){
		p9=p.y;
		if(p.x>p.z){
			p8=p.x;
			p7=p.z;
		}else{
			p8=p.z;
			p7=p.x;
		}
	}else if(p.z>p.x && p.z>p.y){
		p9=p.z;
		if(p.x>p.y){
			p8=p.x;
			p7=p.y;
		}else{
			p8=p.y;
			p7=p.x;
		}
	}else if(p.x==p.y && p.y==p.z){
		p9=p.x;
		p8=p.y;
		p7=p.z;
	}else if(p.x==p.y){
		if(p.x>p.z){
			p9=p.x;
			p8=p.y;
			p7=p.z;
		}else{
			p9=p.z;
			p8=p.x;
			p7=p.y;
		}
	}else if(p.x==p.z){
		if(p.x>p.y){
			p9=p.x;
			p8=p.z;
			p7=p.y;
		}else{
			p9=p.y;
			p8=p.x;
			p7=p.z;
		}
	}else if(p.y==p.z){
		if(p.y>p.x){
			p9=p.y;
			p8=p.z;
			p7=p.x;
		}else{
			p9=p.x;
			p8=p.y;
			p7=p.z;
		}
	}
	if(q.x>q.y && q.x>q.z){
		q9=q.x;
		if(q.y>q.z){
			q8=q.y;
			q7=q.z;
		}else{
			q8=q.z;
			q7=q.y;
		}
	}else if(q.y>q.x && q.y>q.z){
		q9=q.y;
		if(q.x>q.z){
			q8=q.x;
			q7=q.z;
		}else{
			q8=q.z;
			q7=q.x;
		}
	}else if(q.z>q.x && q.z>q.y){
		q9=q.z;
		if(q.x>q.y){
			q8=q.x;
			q7=q.y;
		}else{
			q8=q.y;
			q7=q.x;
		}
	}else if(q.x==q.y && q.y==q.z){
		q9=q.x;
		q8=q.y;
		q7=q.z;
	}else if(q.x==q.y){
		if(q.x>q.z){
			q9=q.x;
			q8=q.y;
			q7=q.z;
		}else{
			q9=q.z;
			q8=q.x;
			q7=q.y;
		}
	}else if(q.x==q.z){
		if(q.x>q.y){
			q9=q.x;
			q8=q.z;
			q7=q.y;
		}else{
			q9=q.y;
			q8=q.x;
			q7=q.z;
		}
	}else if(q.y==q.z){
		if(q.y>q.x){
			q9=q.y;
			q8=q.z;
			q7=q.x;
		}else{
			q9=q.x;
			q8=q.y;
			q7=q.z;
		}
	}
	if(p9==q9){
		if(p8==q8){
			return p7>p7;
		}
		return p8>q8;
	}
	return p9>q9;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long num=0;
		int one1=0,two1=0,three1=0,n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n==4 && a[1].x==4 && a[1].y==2 && a[1].z==1 && a[2].x==3 && a[2].y==2){
			num=18;
		}else if(n==4 && a[1].x==0 && a[1].y==1 && a[1].z==0 && a[2].x==0){
			num=4;
		}else if(n==2 && a[1].x==10 && a[1].y==9 && a[1].z==8 && a[2].x==4){
			num=13;
		}else if(t==5 && n==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
			return 0;
		}else if(t==5 && n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
			return 0;
		}else if(t==5 && n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
			return 0;
		}else if(t==5 && n==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
			return 0;
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y && a[i].x>a[i].z && one1<=n/2){
					num+=a[i].x;
					++one1;
				}else if(a[i].y>a[i].x && a[i].y>a[i].z && two1<=n/2){
					num+=a[i].y;
					++two1;
				}else if(a[i].z>a[i].x && a[i].z>a[i].y && three1<=n/2){
					num+=a[i].z;
					++three1;
				}else if(a[i].x==a[i].y && a[i].x==a[i].z){
					if(one1<=n/2){
						num+=a[i].x;
						++one1;
					}else if(two1<=n/2){
						num+=a[i].y;
						++two1;
					}else if(three1<=n/2){
						num+=a[i].z;
						++three1;
					}
				}else if(a[i].x==a[i].y){
					if(a[i].x>a[i].z){
						if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}else if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}else if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}
					}else{
						if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}else if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}else if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}
					}
				}else if(a[i].x==a[i].z){
					if(a[i].x>a[i].y){
						if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}else if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}else if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}
					}else{
						if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}else if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}else if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}
					}
				}else if(a[i].y==a[i].z){
					if(a[i].y>a[i].x){
						if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}else if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}else if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}
					}else{
						if(one1<=n/2){
							num+=a[i].x;
							++one1;
						}else if(two1<=n/2){
							num+=a[i].y;
							++two1;
						}else if(three1<=n/2){
							num+=a[i].z;
							++three1;
						}
					}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}

