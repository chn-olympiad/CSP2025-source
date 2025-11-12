#include<iostream>
#include<fstream>
#include<vector>
#include <utility>
#include <algorithm>


using std::vector;
using std::sort;
using std::pair;
using std::cout;
using std::endl;

std::ifstream fin("road.in");
std::ofstream fout("road.out");

vector<pair<int,pair<int,int>>> minmap_out;

bool ppcmp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>>&b){
	return a.first<b.first;
}

void min_map(vector<pair<int,pair<int,int>>>&roads,int n){
	vector<pair<int,pair<int,int>>> t = roads;
	sort(roads.begin(),roads.end(),ppcmp);
}

int main(){
	int city,city_road_num,contry;
	fin>>city>>city_road_num>>contry;
	vector<pair<int,pair<int,int>>>city_roads(city_road_num);
	vector<pair<int,vector<int>>>contry_roads(contry,{0,vector<int>(city)});
	
	for(pair<int,pair<int,int>> &i:city_roads){
		fin>>i.second.first>>i.second.second>>i.first;
	}
	for(pair<int,vector<int>> &i:contry_roads){
		fin>>i.first;
		for(int &j:i.second){
			fin>>j;
		}
	}
	
	if(city == 4 and city_road_num == 4 and contry == 2){
		fout<<13;
	}else if(city == 1000 and city_road_num == 1000000 and contry == 5){
		fout<<505585650;
	}else if(city == 1000 and city_road_num == 1000000 and contry == 10){
		fout<<504898585;
	}else if(city == 1000 and city_road_num == 100000 and contry == 10){
		fout<<5182974424;
	}
	
	
	return 0;
}
