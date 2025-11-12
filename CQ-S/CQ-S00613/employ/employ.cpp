#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
				
					}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
			
			} 
			
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					
					two.push_back(one[i]);
					
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].e-two[0].w;
						cnt3--;
					}
				}
				
			}
			
		}
		cout<<sum<<endl;
	}
}
/*#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}#include<iostream>
#include<vector>
using namespace std;
struct ok{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		ok o[a];
		int cnt1=0,cnt2=0,cnt3=0;
		vector<ok> one,two,three;
		long long sum=0;
		for(int i=0;i<a;i++){
			cin>>o[i].q>>o[i].w>>o[i].e;
			int k=max(o[i].w,o[i].q);
			k=max(k,o[i].e);
			if(k==o[i].q){
				
				cnt1++;
				one.push_back(o[i]);
			}
			if(k==o[i].w){
				
				cnt2++;
				two.push_back(o[i]);
			}
			if(k==o[i].e){
				
				cnt3++;
				three.push_back(o[i]);
			}
			sum+=k;
		}
		if(cnt1<cnt2){
			swap(cnt1,cnt2);
			swap(one,two); 
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].w);
			}
			for(int i=0;i<cnt2;i++){
				swap(two[i].q,two[i].w);
			}
		}
		if(cnt1<cnt3){
			swap(cnt1,cnt3);
			swap(one,three);
			for(int i=0;i<cnt1;i++){
				swap(one[i].q,one[i].e);
			}
			for(int i=0;i<cnt3;i++){
				swap(three[i].q,three[i].e);
			}
		}
		for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<'\n';
		}
		if(cnt1>a/2){
			for(int i=0;i<cnt1-1;i++){
				for(int j=0;j<cnt1-1-i;j++){
					int sec1=one[j].q-max(one[j].w,one[j].e),sec2=one[j+1].q-max(one[j+1].w,one[j+1].e);
					if(sec1>sec2)swap(one[j],one[j+1]);
				}
				for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";}
			} 
			for(int i=0;i<cnt1;i++){
			cout<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		cout<<'\n';
			for(int i=0;i<cnt1-a/2;i++){
				if(one[i].w>=one[i].e){
					cnt2++;
					two.push_back(one[i]);
					sum-=one[i].q-one[i].w;
					if(cnt2>a/2){
						for(int j=0;j<cnt2-1;j++){
							int sec1=two[j].w-two[j].e,sec2=two[j+1].w-two[j+1].e;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt3++;
						sum-=two[0].w-two[0].e;
						cnt2--;
					}
				}
				else{
					cnt3++;
					three.push_back(one[i]);
					sum-=one[i].q-one[i].e;
					if(cnt3>a/2){
						for(int j=0;j<cnt3-1;j++){
							int sec1=two[j].e-two[j].w,sec2=two[j+1].e-two[j+1].w;
							if(sec1>sec2)swap(two[j],two[j+1]);
						}
						cnt2++;
						sum-=two[0].w-two[0].e;
						cnt3--;
					}
				}
			}
			for(int i=0;i<cnt1;i++){
			cout<<'\n'<<one[i].q<<' '<<one[i].w<<' '<<one[i].e<<"\n";
		}
		}
		cout<<sum<<endl;
	}
}*/ 
