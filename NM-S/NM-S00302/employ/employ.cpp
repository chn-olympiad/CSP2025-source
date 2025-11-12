#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct g{
	long long a,b,c;
}a[100001];

long long cz(g e){
	if(e.a>e.b){
		if(e.a>e.c){
			return e.a-max(e.b,e.c);
		}else{
			return e.c-max(e.a,e.b);
		}
	}else{
		if(e.b>e.c){
			return e.b-max(e.a,e.c);
		}else{
			return e.c-max(e.a,e.b);
		}
	}
}

bool cmp(g xx,g yy){
if(cz(xx)==cz(yy)){
    	if(xx.a>xx.b){
		if(xx.a>xx.c){
			if(yy.a>yy.b){
				if(yy.c<yy.a){
					return xx.a>yy.a;
				}else{
					return xx.a>yy.c;
				}
			}else{
				return xx.a>yy.b;
			}
		}else{
			if(yy.a>yy.b){
				if(yy.c<yy.a){
					return xx.c>yy.a;
				}else{
					return xx.c>yy.c;
				}
			}else{
				return xx.c>yy.b;
			}
		}
	}else{
		if(xx.b>xx.c){
			if(yy.a>yy.b){
				if(yy.c<yy.a){
					return xx.b>yy.a;
				}else{
					return xx.b>yy.c;
				}
			}else{
				return xx.b>yy.b;
			}
		}else{
			if(yy.a>yy.b){
				if(yy.c<yy.a){
					return xx.c>yy.a;
				}else{
					return xx.c>yy.c;
				}
			}else{
				return xx.c>yy.b;
			}
		}
    }
}
return cz(xx)>cz(yy);
}



long long aa[100001],bb[100001],cc[100001];
long long ansa,ansb,ansc,sum;
long long na,nb,nc;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	while(t>0){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		//cout<<"a[i].abc:";//bug
		for(long long i=1;i<=n;i++){
			if(a[i].a>a[i].b){
				if(a[i].a>a[i].c){
					aa[i]++;
					ansa++;
					//cout<<a[i].a<<' ';//bug
				}else{
					cc[i]++;
					ansc++;
					//cout<<a[i].c<<' ';//bug
				}
			}else{
				if(a[i].b<a[i].c){
					cc[i]++;
					//cout<<a[i].c<<' ';//bug
					ansc++;
				}else{
					bb[i]++;
					//cout<<a[i].b<<' ';//bug
					ansb++;
				}
			}
		}/*///bug
		//cout<<"aabbcc:";
		for(int i=1;i<=n;i++){
			cout<<aa[i]<<" "<<bb[i]<<' '<<cc[i]<<endl;
		}
		cout<<"cmp:"<<endl;

		for(int i=1;i<=n;i++){
		    cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<cz(a[i])<<endl;
		}
		cout<<"ans:"<<ansa<<' '<<ansb<<' '<<ansc<<endl;/*/
		if(ansa<=n/2&&ansb<=n/2&&ansc<=n/2){
			for(long long i=1;i<=n;i++){
				if(aa[i]==1){
					sum+=a[i].a;
				}else if(bb[i]==1){
					sum+=a[i].b;
				}else{
					sum+=a[i].c;
				}
				//cout<<sum<<' ';
		    }
		}else if(ansa>n/2){
			na=0;
			for(long long i=1;i<=n;i++){
				if(aa[i]==1&&na<n/2){
					sum+=a[i].a;
					na++;
				}else if(bb[i]==1){
					sum+=a[i].b;
				}else if(cc[i]==1){
					sum+=a[i].c;
				}else if(aa[i]==1&&na>=n/2){
					if(a[i].b>a[i].c){
						sum+=a[i].b;
					}else{
						sum+=a[i].c;
					}
				}
				//cout<<sum<<' ';//bug
			}
		}else if(ansb>n/2){
			nb=0;
			for(long long i=1;i<=n;i++){
			    if(aa[i]==1){
					sum+=a[i].a;
			    }else if(bb[i]==1&&nb<n/2){
					sum+=a[i].b;
					nb++;
			    }else if(cc[i]==1){
					sum+=a[i].c;
			    }else if(bb[i]==1&&nb>=n/2){
				    if(a[i].a>a[i].c){
					    sum+=a[i].a;
			        }else{
					    sum+=a[i].c;
				    }
			    }
			    //cout<<sum<<' ';//bug
		    }
		}else if(ansc>n/2){
			nc=0;
			for(long long i=1;i<=n;i++){
			    if(aa[i]==1){
					sum+=a[i].a;
		    	}else if(bb[i]==1){
		  			sum+=a[i].b;
		    	}else if(cc[i]==1&&nc<n/2){
		  			sum+=a[i].c;
		  			nc++;
		    	}else if(cc[i]==1&&nc>=n/2){
			    	if(a[i].a>a[i].b){
				    	sum+=a[i].a;
			    	}else{
				    	sum+=a[i].b;
				    }
			    }
			    //cout<<sum<<' ';//bug
		    }
		}
		cout<<sum<<endl;
		t--;
		for(int i=1;i<=n;i++){
			aa[i]=0;
			bb[i]=0;
			cc[i]=0;
		}
		ansa=0;
		ansb=0;
		ansc=0;
	}

	return 0;
}
