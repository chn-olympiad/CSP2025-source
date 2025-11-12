#include<bits/stdc++.h>

using namespace std;

int seed;
int n,p;
string qstr;
string tostr;
int times;
int cache[100001];

string cut(string &Who,int start = -1,int end = -1){
	string out = "";
	if(start == -1){
		start = 0;
	}if(end == -1){
		end = Who.size()-1;
	}
	for(int i = start ; i <= end ; i++){
		out += Who[i];
	}return out;
}


bool is_seem(string A,string B){
	if(A.size() != B.size()){
		return false;
	}int lsize = A.size();
	for(int i = 0 ; i < lsize; i++){
		if(A[i] != B[i]){
			return false;
		}
	}return true;
}

class change{
	public:
	string y;
	string h;
	int xlen;
	void getxlen(){
		xlen = y.size();
		return ;
	}
	string changeit(change* Text,string Who,int Where,int x){
		return cut(Who,-1,Where-1)+Text[x].h+cut(Who,Where+Text[x].xlen+1,-1);
	}
	
	bool is_right(string in,string to,change* Text,int Where,int Which){
		string db = cut(in,-1,xlen-1);
		for(int i = 0 ; i < xlen ; i++){
			if(db[i] != y[i]){
				return false;
			}
		}string doseem = changeit(Text,in,Where,Which);
		if(is_seem(cut(doseem,times++),to)){
			return true;
		}return false;
		
	}
};



int sj(int seed){
	unsigned int c = pow(2,31);
	return (seed*213014+251101)%c;
}

int work_out(string qstr,change* exchange,string todo){
	int answer = 0;
	int lsize = qstr.size();
	for(int j = 0 ; j < lsize ; j++){
		for(int x = 0 ; x < n ; x++){
			if(exchange[x].is_right(qstr,todo,exchange,j,x)){
				answer++;
				break;
			}
		}
	}return answer;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	change exchange[105100];
	cin >> n >> p;
	for(int i = 0 ; i < n ; i++){
		cin >> exchange[i].y >> exchange[i].h;
		exchange[i].getxlen();
	}for(int i = 0 ; i < p ; i++){
		times = 0;
		cin >> qstr;
		cin >> tostr;
		cache[i] = work_out(qstr,exchange,tostr);
	}for(int i = 0 ; i < p ; i++){
		cout << cache[i]/2 << "\n";
	}
	return 0;
}
