#include <bits/stdc++.h>
#include <ipstream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin(club.in);
	ofstream cout(club.out);
	int a,join1,join2,join3,max1,kards,h,somany[10086];
	cin>>a;
	for(int cs = 0;cs < a;cs++){
		int club1[10086],club2[10086],club3[10086];
		join1 = 0;
		join2 = 0;
		join3 = 0;
		kards = 0;
		max1 = 0;
		int a1;
		cin>>a1;
		for(int i = 0;i < a1;i++){
			cin>>club1[i];
			cin>>club2[i];
			cin>>club3[i];
		}
		for(int i = 0;i < a1;i++){
			for(int j = 0;j<a1;j++){
				if(club1[j] > max1){
					max1 = club1[j];
					h = j;
					kards = 1;
						}
				
					}
			for(int j = 0;j<a1;j++){
				if(club2[j] > max1){
					max1 = club2[j];
					h = j;
					kards = 2;
						}
					}
			for(int j = 0;j<a1;j++){
				if(club3[j] > max1){
					max1 = club3[j];
					h = j;
					kards = 3;
						}
					}
			if(kards = 1){
				if(join1 < a1/2){
					join1 += 1;
					somany[cs] += max1;
					max1 = 0;
					club1[h] = -2;
					club2[h] = -2;
					club3[h] = -2;
						}
				if(join1 = a1/2){
					max1 = 0;
					club1[h] = -2;
					i -= 1;
						}
					}
			if(kards = 2){
				if(join2 < a1/2){
					join2 += 1;
					somany[cs] += max1;
					max1 = 0;
					club1[h] = -2;
					club2[h] = -2;
					club3[h] = -2;
						}
				if(join2 = a1/2){
					max1 = 0;
					club2[h] = -2;
					i -= 1;
						}
					}	
			if(kards = 3){
				if(join3 < a1/2){
					join3 += 1;
					somany[cs] += max1;
					max1 = 0;
					club1[h] = -2;
					club2[h] = -2;
					club3[h] = -2;
						}
				if(join3 = a1/2){
					max1 = 0;
					club1[h] = -2;
					i -= 1;
						}
					}
				}
		}
	for(int cs = 0;cs<a;cs++){
		cout<<somany[cs]<<endl;
	}
	return 0;
}
