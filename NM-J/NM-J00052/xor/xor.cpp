#include<bits/stdc++.h>

using namespace std;

int in;
int inl[100100];
int nexts,k,answer;

int mxor(int in1,int in2){
	string sin1,sin2;
	int in1max = 0,in2max = 0,ainmax;
	string ansstr;
	//int to bin string
	if(in1 == 0){
		sin1[in1max++] = '0';
	}
	for( ; in1 > 0 ; ){
		sin1[in1max++] = in1%2+'0';
		in1 = in1/2;
	}
	if(in2 == 0){
		sin2[in2max++] = '0';
	}
	for( ; in2 > 0 ; ){
		sin2[in2max++] = in2%2+'0';
		in2 = in2/2;
	}
	//max
	ainmax = max(in1max,in2max);

	//do xor
	for(int i = 0 ; i < ainmax ; i++){
		if(sin1[i] != sin2[i] 
		|| (in1max-1 < 0 && sin2[i] == '1') 
		|| (in2max-1 < 0 && sin1[i] == '1')){
			ansstr[i] = '1';
		}else{
			ansstr[i] = '0';
		}in1max--;
		in2max--;
	}
	//bin str to int
	int out = 0;
	for(int i = 0 ; i < ainmax ; i++){
		out += (ansstr[i]-'0')*pow(2,i);
	}
	
	return out;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	//in
	cin >> in >> k;
	for(int i = 0 ; i < in ; i++){
		cin >> inl[i];
	}
	
	//group max is?
	nexts = inl[0];
	for(int i = 1 ; i < in ; i++){
		if(nexts == k){
			answer++;
			nexts = inl[i];
		}else{
			nexts = mxor(nexts,inl[i]);
		}
	}if(nexts == k){
		answer++;
	}
	cout << answer;
	
	return 0;
}
