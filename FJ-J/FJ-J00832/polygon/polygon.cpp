#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define MODNUM 998244353
#define MAXER(L,R) ((L)>(R)?(L):(R))
//void case1(){
//	//freopen("polygon.in","r",stdin);
//	//freopen("polygon.out","w",stdout);
//	int n;
//	cin>>n;
//	vector<int> as(n);
//	for(auto &ec:as){
//		cin>>ec;
//	}
//	sort(as.begin(),as.end());//from small to big
//	int methods=0;
//	vector<int> dots;
//	for(int os=0;os<as.size()-2;os++){
//		for(int sbs=2;sbs<as.size()-os;sbs++)//subbed bian shu
//		{
//			long long lensum=0,doumax=-1;
//			dots.reserve(sbs+1);
//			for(int i=0;i<=sbs;i++)dots[i]=i;
//			
//			bool over=0;
//			do{
//				cout<<"sbs$"<<sbs<<"$ os$"<<os<<"$\n";
//				for(int dot=0;dot<=sbs;dot++){
//					lensum+=as[os+dots[dot]];
//					doumax=MAXER(2*as[os+dots[dot]],doumax);
//				}
//				if(lensum>doumax){
//					(++methods)%=MODNUM;
//				}
//				
//				over=1;
//				for(int i=0;i<=sbs;i++){
//					if(dots[i]==as.size()-sbs+i){
//					}else{
//						over=0;
//					}
//				}
//				if(!over){
//					for(int i=0;i<sbs;i++){
//						if(dots[i+1]-dots[i]!=1){
//							dots[i]++;
//							goto adddone;
//						}
//					}
//				}
//				break;
//				adddone:;
//			}while(!over);
//			
////			for(int dot=0;dot<=sbs;dot++){
////				lensum+=as[i+dots[dot]];
////				doumax=MAXER(2*as[i+dots[dot]],doumax);
////			}
////			if(lensum>doumax){
////				(++methods)%=MODNUM;
////			}
//			
//			
//			
//			
//		}
//	}
//	cout<<methods;
//}
vector<vector<int> > all;
vector<string> coda;
void each(vector<int> &beforeVec,vector<int> &afterVec){
	if(afterVec.empty()){
		string codec="";
		for(auto &ec:beforeVec){
			codec+=to_string(ec)+"|";
		}
		//cout<<"codec:"<<codec<<";\n";
		for(auto &ec:coda){
			if(ec==codec)return;
		}
		all.push_back(beforeVec);
		coda.push_back(codec);
		return;
	}
	vector<int> cover=beforeVec;
	for(int post=0;post<afterVec.size();post++){
		cover.push_back(afterVec[post]);
		//int *p=afterVec.data()+post+1;
		vector<int> newafterVec;
		for(int afterVecP=post+1;afterVecP<afterVec.size();
			afterVecP++){
			newafterVec.push_back(afterVec[afterVecP]);
		}
	
		each(cover,newafterVec);
		cover.erase(cover.begin()+cover.size()-1,
			cover.begin()+cover.size()-1);
	}
}
int canbe(const vector<int> &lok){
	int sum=0,mxn=-1;
	for(const int &ec:lok){
		sum+=ec;
		mxn=MAXER(ec,mxn);
	}
	return sum>(2*mxn);
}
void case2(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> as(n);
	for(auto &ec:as){
		cin>>ec;
	}
	sort(as.begin(),as.end());//from small to big
	int methods=0;
	vector<int> nil;
	each(as,nil);
	for(auto &ec:all){
		methods+=canbe(ec);
	}
	cout<<methods;
}
int main(){
	case2();
	//too ba-d!!! 
	//this problem isn't perfect(also the last one)
	//i am dryi-ng
}
